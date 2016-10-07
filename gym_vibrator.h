/**
 * @brief Vibrator motor class 
 */
 
 #ifndef __GYM_VIBRATOR_H
 #define __GYM_VIBRATOR_H
 
 #include "mbed.h"
 #include "rtos.h"
 #include "PwmOut.h"
 #include "Timeout.h"
 
/* defines the properties of vibrator class */
class watch_viber : public PwmOut{

public:

	/**
	 * @brief constructor creates a vibrator in specified pin
	 */
    watch_viber(PinName vib_pin);
    virtual ~watch_viber();
    

    /**
     * @brief triggers the vibration for a specified time
     */
    void watch_start_viber(int ticks);

    /**
     * @brief stop current vibration action
     */
    void watch_stop_viber(void);

private:
    void viber_callback(void);
    bool vibrating;
    Timeout *vib_tout;
};

 
 
 #endif
