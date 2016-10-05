/**
 * @brief smartwatch ihm service manager 
 */
 
 #include "gym_watch.h"
 #include "gym_ihm.h"
 #include "OLED_types.h"
 


  
watch_ihm::watch_ihm(PinName mosiPin,PinName sclkPin,
                    PinName pwrPin, PinName csPin,PinName rstPin, 
                    PinName dcPin) : SSD1351 (mosiPin, sclkPin, pwrPin,csPin,
                                                 rstPin, dcPin) {
    ihm_thread_stk = new unsigned char [1024];
    ihm_thread = new Thread(IHM_PRIO, 1024, ihm_thread_stk);
 }

watch_ihm::~watch_ihm() {
    delete[] ihm_thread_stk;
    delete ihm_thread;
}

int watch_ihm::watch_ihm_add_menu(watch_menu *m){
    watch_menu *ptr = current_menu;
 
    if(current_menu == NULL) {
        /* the ihm has no menu installed */
        current_menu = m;
        
        return(0);
    }
 
    while(ptr->menu_get_child() != NULL) {
        /* iterate and finds the last item added */
        ptr = ptr->menu_get_child();
    }
    /* insert this child on the list*/
    ptr->menu_add_child(m);
    return(0);
}

int watch_ihm::watch_ihm_rm_menu(watch_menu *m) {
    /* Remotion is not needed now */
    return -1;
}

Thread* watch_ihm::watch_ihm_get_input_channel(void){
    return(ihm_thread);
}

void watch_ihm::watch_ihm_start(void) {
    /* starts the thread */
    ihm_thread->start(this, &watch_ihm::ihm_manager);
}

void watch_ihm::ihm_manager(void) {    
    oled_text_properties_t default_text;
    osEvent events; 
    event_defaults menu_ret = MENU_CAPTURED; 
    int mask;
    bool app_drawn = false;  
    bool menu_drawn = true;  
      
    /* initialize screen parameters */
    this->GetTextProperties(&default_text);
    this->SetTextProperties(&default_text);    
    this->DimScreenOFF();       
    this->FillScreen(COLOR_MAGENTA);

    for(;;) {
        unsigned int size = 0;
        unsigned char *img_ptr = NULL;
        mask = 0;
        
        /* IHM will be triggered from external events */
        events = this->signal_wait(EVENT_TOUCH_ALL,osWaitForever);
        /* reset the waited signals */
        this->signal_clr((events.value.signals));

        if(current_menu != NULL) {
           mask = current_menu->menu_get_event_mask();
           
           /* masks and uses only menu accepted events */
           mask &= events.value.signals; 
 
        }
        
        if(mask != 0) {
            /* execute menu application function */
            menu_ret = current_menu->menu_execute_callback(&mask);                     
            
    
            /* handle the response of custom menu function */
            switch(menu_ret) {
                case MENU_CAPTURED:
                    /* keeps the current menu 
                     * camn be treated as a ok button
                     */
                     app_drawn = true;
                     menu_drawn = false;
                break;    
            
                case MENU_GO_TO_CHILD:
                    if(app_drawn == false ){
                        current_menu = current_menu->menu_get_child();
                        
                        current_menu->menu_get_image(img_ptr, &size);
                        /* select drawing type */
                        if(img_ptr != NULL) {
                            this->DrawScreen(img_ptr, 0, 0, 96,96, OLED_TRANSITION_TOP_DOWN);
                        } else {
                            this->FillScreen(COLOR_BLACK);
                        } 
                    }   
                break;
                
                case MENU_GO_TO_PARENT:
                    if(app_drawn == false) {
                        current_menu = current_menu->menu_get_parent();
                        
                        current_menu->menu_get_image(img_ptr, &size);
                        /* select drawing type */
                        if(img_ptr != NULL) {
                            this->DrawScreen(img_ptr, 0, 0, 96,96, OLED_TRANSITION_TOP_DOWN);
                        } else {
                            this->FillScreen(COLOR_BLACK);
                        } 
    
                    }                
                break;
                
                case MENU_EXIT:
                    if(menu_drawn == false) {
                        app_drawn = false;
                        
                        current_menu->menu_get_image(img_ptr, &size);
                        /* select drawing type */
                        if(img_ptr != NULL) {
                            this->DrawScreen(img_ptr, 0, 0, 96,96, OLED_TRANSITION_TOP_DOWN);
                        } else {
                            this->FillScreen(COLOR_BLACK);
                        } 
                        
                        menu_drawn = true;
                                    
                    }
                break;
            }       
        }
    }
}
