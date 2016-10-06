/**
 * @brief pedometer application class
 */


#include "gym_ihm.h"
#include "gym_pedometer.h"


/* image of pedometer application shown in lcd */
const unsigned char pedometer_app_image[1024] ={0};

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
	pedometer_menu->menu_set_callback(&pedometer_app::pedometer_callback);

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


event_defaults pedometer_app::pedometer_callback(void *args){
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
			pedometer_app_thread->signal_set(1);
			ret = MENU_CAPTURED;
			break;

		case EVENT_TOUCH_UP:
			/* suspend application task from run */
			pedometer_app_thread->signal_clr(1);
			ret = MENU_EXIT;

			break;
	}
	return(ret);
}

void pedometer_app::pedometer_app_task(void){
	/* sets the image of pedometer */
	pedometer_menu->menu_set_image((unsigned char *)&pedometer_app_image[0], sizeof(pedometer_app_image));

	for(;;) {
		/* wait for a ihm running request */
		pedometer_app_thread->signal_wait(1, osWaitForever);

	}
}
