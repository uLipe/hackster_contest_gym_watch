/**
 * @brief class which handles the hw events 
 */
 
#include "gym_watch.h"
#include "gym_ihm_input.h"


ihm_input *current_input;

void upkey (void){
    current_input->signal_set(EVENT_TOUCH | EVENT_TOUCH_UP);
}     


void dokey (void){
    current_input->signal_set(EVENT_TOUCH | EVENT_TOUCH_DO);
}

void rikey (void){
    current_input->signal_set(EVENT_TOUCH | EVENT_TOUCH_RI);
}

void lfkey (void){
    current_input->signal_set(EVENT_TOUCH | EVENT_TOUCH_LF);    
}



ihm_input::ihm_input(PinName tx, PinName rx) : KW40Z(tx, rx)  {
    ihm_input_stk = new unsigned char [1024];
    ihm_input_thread = new Thread(osPriorityRealtime, 1024, ihm_input_stk);
    ihm_signal = new Semaphore;
    key_viber = new watch_viber(PTB9);    
}


ihm_input::~ihm_input(){
    delete[] ihm_input_stk;
    delete ihm_input_thread;
}

void ihm_input::ihm_input_start(void){
    ihm_input_thread->start(this, &ihm_input::input_task);
}

void ihm_input::attach_thread(Thread* thr){
    /* 
     * Register the output thread to be signaled when 
     * a touch key is pressed
     */
    out_channel = thr;    
}    



void ihm_input::input_task(void){
    osEvent events;
 
    current_input = this;
    
    this->attach_buttonUp(upkey);
    this->attach_buttonDown(dokey);
    this->attach_buttonLeft(lfkey);
    this->attach_buttonRight(rikey);
    
    
    for(;;) {
        /* remove the touch base event and send only the key */
        events = this->signal_wait(EVENT_TOUCH,osWaitForever);
        
        key_viber->watch_stop_viber();        
        key_viber->watch_start_viber(1);
        
        
        
        /* resets the signals waited*/
        this->signal_clr(events.value.signals);
        events.value.signals &= ~(EVENT_TOUCH);
        if(out_channel != NULL) {
            out_channel->signal_set(events.value.signals);      
        }
        
    }  
}
    
