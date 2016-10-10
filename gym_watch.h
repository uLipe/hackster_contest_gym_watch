/**
 * @brief gym watch master file, include all headers here
 */
 
 
 #ifndef __GYM_WATCH_H
 #define __GYM_WATCH_H
  
 #include "mbed.h"
 #include "rtos.h"
 
 /* Include the hexiwear specific drivers */
 #include "Hexi_OLED_SSD1351.h"
 #include "Hexi_KW40Z.h"
 #include "FXOS8700CQ.h"
  
 /* include here the priority list */
 #define ACC_PRIO                   osPriorityRealtime
 #define HEART_RATE_PRIO            osPriorityRealtime
 #define TOUCH_PRIO                 osPriorityRealtime
 #define IHM_PRIO                   osPriorityNormal
 #define PWR_PRIO                   osPriorityNormal
 #define EXERCISE_PRIO              osPriorityHigh
 
 
 /* event types */
 #define EVENT_TOUCH                0x0000001
 #define EVENT_SW                   0x0000002
 #define EVENT_HW                   0x0000004
 #define EVENT_HRM                  0x0000008
 #define EVENT_ACC                  0x0000010
 #define EVENT_ALL   (EVENT_TOUCH|EVENT_SW|EVENT_HW|EVENT_HRM|EVENT_ACC)


 #define EVENT_TOUCH_UP             0x0000100
 #define EVENT_TOUCH_DO             0x0000200
 #define EVENT_TOUCH_LF             0x0000400
 #define EVENT_TOUCH_RI             0x0000800
 #define EVENT_TOUCH_ALL (EVENT_TOUCH_UP | EVENT_TOUCH_DO |    \
                         EVENT_TOUCH_LF | EVENT_TOUCH_RI)     


 #endif
 
 
 
 
 
 
 
 
 
 
