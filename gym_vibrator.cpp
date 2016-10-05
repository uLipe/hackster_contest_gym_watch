/**
 * @brief Vibrator motor class 
 */
 
#include "gym_watch.h"
#include "gym_vibrator.h"
 
const int pwm_period_ms = 2; 
 

watch_viber::watch_viber(PinName vib_pin) : PwmOut(vib_pin){
    
    vibrating = false;
    vib_tout = new Timeout;
    this->period_ms(pwm_period_ms);
    this->write(0);
}

watch_viber::~watch_viber(){
}

void watch_viber::watch_start_viber(int ticks){
    
    /* turn vibrator on */
    this->write(50);
    vib_tout->attach(this, &watch_viber::viber_callback,ticks);
}    
void watch_viber::watch_stop_viber(void){
    /* abort vibrating operation */
    this->write(0);
    vib_tout->detach();
}

void watch_viber::viber_callback(void) {
    this->write(0);
    vib_tout->detach();
}