/**
 * @brief gym exercise counter app
 */
#ifndef GYM_EXERCISE_COUNTER_H_
#define GYM_EXERCISE_COUNTER_H_

#include "gym_menu.h"
#include "gym_watch.h"


/**
 * @brief defines the exercise counter class
 */

class gym_exercise {
public:
	gym_exercise();
	virtual ~gym_exercise();
	void gym_exercise_start(void);
	watch_menu * gym_exercise_get_menu(void);

private:
    unsigned char *exercise_stk;
    Thread *exercise_app_thread;
    void exercise_app_task(void);
    event_defaults exercise_callback(void *args);
    watch_menu *exercise_menu;
};



#endif /* GYM_EXERCISE_COUNTER_H_ */
