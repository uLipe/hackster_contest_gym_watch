/**
 * @brief heart rate monitor app 
 */

#include "heart_rate_app.h"
#include "gym_watch.h"
#include "I2C.h"

#define HRM_SLAVE_ADDR ((0x57)<< 1)


extern const unsigned char hr_app_image[];
extern int heart_size;
extern const unsigned char empty_drawable[];
extern int empty_size;

extern watch_ihm main_ihm;
Thread *current_hr;
watch_menu *current_hr_m;



hr_app::hr_app(){
	hr_stk = new unsigned char[1024];
	hr_app_thread = new Thread(osPriorityRealtime, 1024, hr_stk);
}


hr_app::~hr_app(){

}


void hr_app::hr_start(void){

	/* before start creates a menu instance to use with ihm */
	hr_menu = new watch_menu;

	/* triggers the thread */
	hr_app_thread->start(this, &hr_app::hr_app_task);
}

watch_menu *hr_app::get_hr_menu(){

	watch_menu *ret = NULL;
	if(hr_menu != NULL) {
		ret = hr_menu;
	}

	/* return the current menu of heart rate app, if exists */
	return(ret);

}    

event_defaults hr_app::hr_callback(int args) {
	event_defaults ret = MENU_CAPTURED;
	int input = (int)args;


	switch(input) {
		case EVENT_TOUCH_RI:
			if(current_hr_m->state != MENU_IN_APP) {
				ret = MENU_GO_TO_CHILD;
			} else {
				ret = MENU_CAPTURED;
			}

			break;

		case EVENT_TOUCH_LF:
			if(current_hr_m->state != MENU_IN_APP) {
				ret = MENU_GO_TO_PARENT;
			} else {

				current_hr_m->state = MENU_IN_SCREEN;
				/* suspend application task from run */
				current_hr->signal_clr(1);
				ret = MENU_EXIT;
			}
			break;

		case EVENT_TOUCH_DO:
			if(current_hr_m->state != MENU_IN_APP) {
				current_hr->signal_set(1);
				ret = MENU_CAPTURED;
			}
			break;

		case EVENT_TOUCH_UP:
			ret = MENU_CAPTURED;
			break;
	}
	return(ret);
}

void hr_app::hr_app_task(void){
	I2C *i2c_hr_sensor = new I2C(PTB1, PTB0);
	osEvent event;
	bool need_draw = true;
    char i2c_data_single[2] = {0};

	/* sets the default image of this menu */
	hr_menu->menu_set_image((unsigned char *)&hr_app_image[0], heart_size);
	/* sets the interface frequency */
	i2c_hr_sensor->frequency(100000);
	hr_menu->set_menu_thread(hr_app_thread);
	hr_menu->menu_set_callback(&hr_app::hr_callback);
	hr_menu->menu_set_event_mask(EVENT_TOUCH_ALL);

	current_hr = hr_app_thread;
	current_hr_m = hr_menu;

    i2c_data_single[0] = 0x08;
    i2c_data_single[1] = 0x10;
    i2c_hr_sensor->write(HRM_SLAVE_ADDR,(char *)i2c_data_single,2, false);


    i2c_data_single[0] = 0x0C;
    i2c_data_single[1] = 0x7F;
    i2c_hr_sensor->write(HRM_SLAVE_ADDR,i2c_data_single,sizeof(i2c_data_single), false);


    i2c_data_single[0] = 0x0D;
    i2c_data_single[1] = 0x7F;
    i2c_hr_sensor->write(HRM_SLAVE_ADDR,i2c_data_single,sizeof(i2c_data_single), false);

    i2c_data_single[0] = 0x0E;
    i2c_data_single[1] = 0x7F;
    i2c_hr_sensor->write(HRM_SLAVE_ADDR,i2c_data_single,sizeof(i2c_data_single), false);

    i2c_data_single[0] = 0x0A;
    i2c_data_single[1] = 0x03;
    i2c_hr_sensor->write(HRM_SLAVE_ADDR,i2c_data_single,sizeof(i2c_data_single), false);


    i2c_data_single[0] = 0x09;
    i2c_data_single[1] = 0x02;
    i2c_hr_sensor->write(HRM_SLAVE_ADDR,i2c_data_single,sizeof(i2c_data_single), false);


	for(;;) {
		/* suspends until request */
		hr_app_thread->signal_wait(1,osWaitForever);
		hr_menu->state = MENU_IN_APP;

		if(need_draw != false) {
			/* draw a empty screen */
			main_ihm.DrawScreen(&empty_drawable[0],0,0,96,96, OLED_TRANSITION_NONE);
			need_draw = false;
		}






		event = hr_app_thread->signal_wait(1, 0);
		if(event.value.signals == 0) {
			need_draw = true;
		}
	}

}
