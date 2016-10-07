/**
 * @brief smartwatch ihm service manager 
 */

#ifndef __GYM_IHM
#define __GYM_IHM

#include "gym_menu.h"
#include "Hexi_OLED_SSD1351.h"
#include "mbed.h"
#include "rtos.h"

/**
 * @brief ihm manager service class
 */
class watch_ihm: public Thread, public SSD1351 {

public:
	/**
	 * @brief constructor / destructor
	 */
	watch_ihm(PinName mosiPin, PinName sclkPin, PinName pwrPin, PinName csPin,
			PinName rstPin, PinName dcPin);
	virtual ~watch_ihm();


	/**
	 * @brief add menu to ihm menu list
	 */
	int watch_ihm_add_menu(watch_menu *m);

	/**
	 * @brief remove menu from ihm list
	 */
	int watch_ihm_rm_menu(watch_menu *m);

	/**
	 * @brief starts the ihm application task
	 */
	void watch_ihm_start(void);

	/**
	 * @brief links the hw event input to ihm application
	 */
	Thread* watch_ihm_get_input_channel(void);


private:
	Thread *ihm_thread;
	unsigned char *ihm_thread_stk;
	void ihm_manager(void);
	watch_menu *current_menu;
};

#endif
