/**
 * @brief Vibrator motor class 
 */
 
#include "gym_watch.h"
#include "gym_vibrator.h"
 
const int pwm_period_ms = 2; 
 

watch_viber::watch_viber(PinName vib_pin) {
    vibrating = false;
    vib_tout = new Timeout;
    out = new DigitalOut(vib_pin);
    *out = 0;
}

watch_viber::~watch_viber(){
}

void watch_viber::watch_start_viber(int ticks){
    
    /* turn vibrator on */
	*out = 1;
    vib_tout->attach(this, &watch_viber::viber_callback,ticks);
}    
void watch_viber::watch_stop_viber(void){
    /* abort vibrating operation */
    *out = 0;
    vib_tout->detach();
}

void watch_viber::viber_callback(void) {
    *out = 0;
    vib_tout->detach();
}
