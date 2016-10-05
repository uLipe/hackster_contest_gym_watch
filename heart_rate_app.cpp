/**
 * @brief heart rate monitor app 
 */

#include "heart_rate_app.h"
#include "gym_watch.h"
#include "I2C.h"


const unsigned char hr_app_image[1024] ={0};


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

event_defaults hr_app::hr_callback(void *args) {
	event_defaults ret = MENU_CAPTURED;
	int input = (int)args;


	switch(input) {
		case EVENT_TOUCH_RI:
			ret = MENU_GO_TO_CHILD;
			break;

		case EVENT_TOUCH_LF:
			ret = MENU_GO_TO_PARENT;
			break;

		case EVENT_TOUCH_DO:
			hr_app_thread->signal_set(1);
			ret = MENU_CAPTURED;
			break;

		case EVENT_TOUCH_UP:
			/* suspend application task from run */
			hr_app_thread->signal_clr(1);
			ret = MENU_EXIT;

			break;
	}
	return(ret);
}

void hr_app::hr_app_task(void){
	I2C *i2c_hr_sensor = new I2C(PTB1, PTB0);

	/* sets the default image of this menu */
	hr_menu->menu_set_image((unsigned char *)&hr_app_image[0], sizeof(hr_app_image));
	/* sets the interface frequency */
	i2c_hr_sensor->frequency(100000);
	hr_menu->menu_set_callback(&hr_app::hr_callback);


	for(;;) {
		/* suspends until request */
		hr_app_thread->signal_wait(1,osWaitForever);


		/* todo add processing here */
	}

}
