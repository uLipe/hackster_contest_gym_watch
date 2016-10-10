/**
 * @brief heart rate monitor application 
 */
 
 #ifndef __HEART_RATE_APP
 #define __HEART_RATE_APP
 
 #include "gym_watch.h"
 #include "gym_menu.h"
 #include "gym_ihm.h"
 
 
 /* heart rate app class */
 class hr_app {
 public:
	/**
	 * @brief constructor / destructor
	 */
    hr_app();
    virtual ~hr_app();

    /**
     * @brief starts the hear rate measurement application
     */
    void hr_start(void);

    /**
     * @brief gets the current menu entry of heart rate app
     */
    watch_menu *get_hr_menu();
    
 private:    
    unsigned char *hr_stk;
    Thread *hr_app_thread;
    void hr_app_task(void);
    event_defaults hr_callback(int args);
    watch_menu *hr_menu;
 };
 
 #endif
