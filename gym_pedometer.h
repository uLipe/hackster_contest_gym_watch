/**
 * @brief pedometer application class
 */
#ifndef GYM_PEDOMETER_H_
#define GYM_PEDOMETER_H_


#include "gym_menu.h"
#include "gym_watch.h"

/**
 * @brief pedometer application class defition
 */
class pedometer_app {
public:
	pedometer_app();
	virtual ~pedometer_app();

	void pedometer_app_start(void);
	watch_menu* get_pedometer_menu(void);
private:

    unsigned char *pedometer_stk;
    Thread *pedometer_app_thread;
    void pedometer_app_task(void);
    event_defaults pedometer_callback(void *args);
    watch_menu *pedometer_menu;

};










#endif /* GYM_PEDOMETER_H_ */
