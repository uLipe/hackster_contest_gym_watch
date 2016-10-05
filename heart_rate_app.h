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
    hr_app();
    virtual ~hr_app();
    void hr_start(void);
    watch_menu *get_hr_menu();
    
 private:    
    unsigned char *hr_stk;
    Thread *hr_app_thread;
    void hr_app_task(void);
    event_defaults hr_callback(void *args);
    watch_menu *hr_menu;
 };
 
 #endif
