/**
 * @brief class which handles the hw events 
 */

#ifndef __GYM_IHM_INPUT_H
#define __GYM_IHM_INPUT_H

#include "gym_watch.h"
#include "gym_vibrator.h"
#include "mbed.h"
#include "Hexi_KW40Z.h" 
#include "rtos.h" 

/**
 * @bbrief hw event channel class
 */
class ihm_input: public Thread, public KW40Z {

public:
	/**
	 * @brief constructor / destructor
	 */
	ihm_input(PinName tx, PinName rx);
	virtual ~ihm_input();

	/**
	 * @brief starts the input application task
	 */
	void ihm_input_start(void);

	/**
	 * @brief attach a thread as sinker of the input generated eventts
	 */
	void attach_thread(Thread *thr);

private:
	Thread *ihm_input_thread;
	Semaphore *ihm_signal;
	unsigned char *ihm_input_stk;
	void input_task(void);
	int event_mask;

	Thread* out_channel;
	watch_viber *key_viber;
};

#endif
