/**
 * @brief gym exercise counter app
 */

#include "gym_exercise_counter.h"

/* image of exercise application shown in lcd */
extern const unsigned char exercise_app_image[];
extern int exercise_size;


gym_exercise::gym_exercise() {
	exercise_stk = new unsigned char[1024];
	exercise_app_thread = new Thread(osPriorityRealtime, 1024, exercise_stk);
}

gym_exercise::~gym_exercise() {
	/* todo adds object destruction */
}

void gym_exercise::gym_exercise_start(void) {

	/* creates a menu instance in order to provide user IHM */
	exercise_menu = new watch_menu;
	exercise_menu->menu_set_callback(&gym_exercise::exercise_callback);
	exercise_menu->menu_set_event_mask(EVENT_TOUCH_ALL);

	/* starts the exercise application task */
	exercise_app_thread->start(this, &gym_exercise::exercise_app_task);
}

watch_menu* gym_exercise::gym_exercise_get_menu(void) {

	if (exercise_menu != NULL) {
		return (exercise_menu);
	} else {
		return (NULL);
	}
}

event_defaults gym_exercise::exercise_callback(int args) {
	event_defaults ret = MENU_CAPTURED;
	int input = (int) args;

	switch (input) {
	case EVENT_TOUCH_RI:
		ret = MENU_GO_TO_CHILD;
		break;

	case EVENT_TOUCH_LF:
		ret = MENU_GO_TO_PARENT;
		break;

	case EVENT_TOUCH_DO:
		exercise_app_thread->signal_set(1);
		ret = MENU_CAPTURED;
		break;

	case EVENT_TOUCH_UP:
		/* suspend application task from run */
		exercise_app_thread->signal_clr(1);
		ret = MENU_EXIT;

		break;
	}
	return (ret);
}

void gym_exercise::exercise_app_task(void) {
	/* sets the image of exercise */
	exercise_menu->menu_set_image((unsigned char *) &exercise_app_image[0],
			exercise_size);

	for (;;) {
		/* wait for a ihm running request */
		exercise_app_thread->signal_wait(1, osWaitForever);

	}
}
