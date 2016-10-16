/**
 * @brief pedometer application class
 */

#include "gym_ihm.h"
#include "gym_pedometer.h"


/* image of pedometer application shown in lcd */
extern const unsigned char pedometer_app_image[];
extern int pedometer_size;
extern const unsigned char empty_ex_drawable[];
extern int empty_ex_size;

extern watch_ihm main_ihm;
Thread *current_pedo;
watch_menu *current_pedo_m;



pedometer_app::pedometer_app() {
	pedometer_stk = new unsigned char[1024];
	pedometer_app_thread = new Thread(osPriorityRealtime, 1024, pedometer_stk);
}

pedometer_app::~pedometer_app(){
	/* todo adds object destruction */
}

void pedometer_app::pedometer_app_start(void) {

	/* creates a menu instance in order to provide user IHM */
	pedometer_menu = new watch_menu;
	pedometer_menu->menu_set_callback( &pedometer_app::pedometer_callback);
	pedometer_menu->menu_set_event_mask(EVENT_TOUCH_ALL);

	current_pedo = pedometer_app_thread;
	current_pedo_m = pedometer_menu;

	/* starts the pedometer application task */
	pedometer_app_thread->start(this, &pedometer_app::pedometer_app_task);
}

watch_menu* pedometer_app::get_pedometer_menu(void) {

	if(pedometer_menu != NULL) {
		return(pedometer_menu);
	} else {
		return (NULL);
	}
}


event_defaults pedometer_app::pedometer_callback(int args){
	event_defaults ret = MENU_CAPTURED;
	int input = (int)args;


	switch(input) {
		case EVENT_TOUCH_RI:
			if(current_pedo_m->state != MENU_IN_APP) {
				ret = MENU_GO_TO_CHILD;
			} else {
				ret = MENU_CAPTURED;
			}

			break;

		case EVENT_TOUCH_LF:
			if(current_pedo_m->state != MENU_IN_APP) {
				ret = MENU_GO_TO_PARENT;
			} else {

				current_pedo_m->state = MENU_IN_SCREEN;
				/* suspend application task from run */
				current_pedo->signal_clr(1);
				ret = MENU_EXIT;
			}
			break;

		case EVENT_TOUCH_DO:
			if(current_pedo_m->state != MENU_IN_APP) {
				current_pedo->signal_set(1);
				ret = MENU_CAPTURED;
			}
			break;

		case EVENT_TOUCH_UP:
			ret = MENU_CAPTURED;
			break;
	}
	return(ret);
}

void pedometer_app::pedometer_app_task(void){
	bool need_draw = true;
	osEvent event;

	/* sets the image of pedometer */
	pedometer_menu->menu_set_image((unsigned char *)&pedometer_app_image[0], pedometer_size);

	for(;;) {
		/* wait for a ihm running request */
		pedometer_app_thread->signal_wait(1, osWaitForever);
		pedometer_menu->state = MENU_IN_APP;

		if(need_draw != false) {
			/* needs redraw, refresh screen */
			need_draw = false;
			main_ihm.DrawScreen(&empty_ex_drawable[0], 0,0,96,96, OLED_TRANSITION_NONE);
		}





		event = pedometer_app_thread->signal_wait(1,0);
		if(event.value.signals == 0) {
			/* current app will suspended, so pend a redraw */
			need_draw = true;
		}

	}
}
