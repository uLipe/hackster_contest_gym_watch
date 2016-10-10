/**
 * @brief basic window class 
 */

#ifndef __GYM_MENU_H
#define __GYM_MENU_H

#include "OLED_types.h"
#include "mbed.h"
#include "rtos.h"
 
/** events returned by the menu callback execution */
typedef enum  {
    MENU_CAPTURED = 0,
    MENU_GO_TO_CHILD ,
    MENU_GO_TO_PARENT,
    MENU_EXIT,
}event_defaults;

typedef enum {
	MENU_IN_APP =0,
	MENU_IN_SCREEN,
}menu_status_t;

/**
 * @brief menu properties class
 */
 class watch_menu {
 public:
  
	/**
	 * @brief constructor / destructor
	 */
    watch_menu();
    virtual ~watch_menu();
    
    /**
     * @brief set the image of menu entry
     */
    void menu_set_image(unsigned char *img, unsigned int size);

    /**
     * @brief gets the image of current menu propertie
     */
    unsigned char *menu_get_image(unsigned int *size);

    /**
     * @brief set the background color
     */
    void menu_set_background(Color_t color);
    /**
     * @brief gets the background color
     */
    void menu_get_background(Color_t *color);

    /**
     *@brief configure the reative event masks
     */
    void menu_set_event_mask(unsigned int mask);

    /**
     * @brief gets the current event masks
     */
    unsigned int menu_get_event_mask(void);

    /**
     * @brief add a child menu on current list
     */
    void menu_add_child(watch_menu* const c);

    /**
     * @brief adds a parent on current menu
     */
    void menu_add_parent(watch_menu* const p);

    /**
     * @brief gets the child and parent menu pointers
     */
    watch_menu *menu_get_parent(void);
    watch_menu *menu_get_child(void);

    /**
     * @brief sets the menu event callback
     */
    void menu_set_callback( event_defaults (*func) (int args));

    template <typename M>
    void menu_set_callback(M method) {
    	menu_set_callback((event_defaults (*)(int))method);
    }


    void set_menu_thread(Thread *p);
    Thread *get_menu_thread(void);


    /**
     * @brief force menu callback execution (used with menu ihm)
     */
    event_defaults menu_execute_callback(int args);

    /**
     * @brief current menu status
     */
    menu_status_t state;

    
 private:
    unsigned char *image;
    int image_size;
    Color_t background;
    unsigned int event_mask;
    event_defaults (*menu_callback) (int);
    watch_menu *parent;
    watch_menu *child;
    Thread *menu_thr;
 };
 
 
 
 
 #endif
