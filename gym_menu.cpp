/**
 * @brief basic window class 
 */

#include "gym_watch.h"
#include "gym_menu.h"


watch_menu::watch_menu() {
    /* initialize the variables with defaults */
    event_mask = 0;
    background = COLOR_BLACK;
    image = NULL;
    child = NULL;
    parent = NULL;
    state = MENU_IN_SCREEN;
} 

watch_menu::~watch_menu() {
    /* nothing to do here for while */    
}

void watch_menu::menu_set_image(unsigned char *img, unsigned int size){
    if(img != NULL) {
        /* passes image by reference and not by copy */
        image = img;
        image_size = size;
    }
}

unsigned char * watch_menu::menu_get_image(unsigned int *size){
    if(image == NULL) {
        return NULL;
    } else {
        *size = image_size;
        return(image);
    }
}

void watch_menu::menu_set_background(Color_t color){
    background = color;
}

void watch_menu::menu_get_background(Color_t *color){
    if(color != NULL){
        *color = background;
    }
}

void watch_menu::menu_set_event_mask(unsigned int mask){
    event_mask = mask;
}
unsigned int watch_menu::menu_get_event_mask(void){
    return(event_mask);
}

void watch_menu::menu_add_child(watch_menu* const c){
    child = c;
} 
void watch_menu::menu_add_parent(watch_menu* const p){
    parent = p;
}
watch_menu* watch_menu::menu_get_parent(void){
    return(parent);
}
watch_menu* watch_menu::menu_get_child(void){
    return(child);
}
void watch_menu::menu_set_callback( event_defaults (*func) (int args )){
    if(func != NULL) {
        menu_callback = func;
    }   
}

void watch_menu::set_menu_thread(Thread *p){
	menu_thr = p;
}
Thread* watch_menu::get_menu_thread(void) {
	return(menu_thr);
}

event_defaults watch_menu::menu_execute_callback(int args){
    return(menu_callback != NULL? menu_callback(args) : MENU_CAPTURED);
}
