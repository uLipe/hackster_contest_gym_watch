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
 
 
class ihm_input : public Thread, public KW40Z {

public:
    ihm_input(PinName tx,PinName rx);
    virtual ~ihm_input();
    void ihm_input_start(void);
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