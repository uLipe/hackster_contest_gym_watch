/**
 * @brief basic window class 
 */
 
 #ifndef __GYM_MENU_H
 #define __GYM_MENU_H
 
 #include "OLED_types.h"  
 
typedef enum  {
    MENU_CAPTURED = 0,
    MENU_GO_TO_CHILD ,
    MENU_GO_TO_PARENT,
    MENU_EXIT,
}event_defaults;

 
 class watch_menu {
 public:
  
    watch_menu();
    ~watch_menu();
    
    void menu_set_image(unsigned char *img, unsigned int size);
    void menu_get_image(unsigned char *img, unsigned int *size);
    void menu_set_background(Color_t color);
    void menu_get_background(Color_t *color);
    void menu_set_event_mask(unsigned int mask);
    unsigned int menu_get_event_mask(void);
    void menu_add_child(watch_menu* const c);
    void menu_add_parent(watch_menu* const p);
    watch_menu *menu_get_parent(void);
    watch_menu *menu_get_child(void);
    void menu_set_callback( event_defaults (*func) (void *args));

    template <typename M>
    void menu_set_callback(M method) {
    	menu_set_callback((event_defaults (*)(void *))method);
    }

    event_defaults menu_execute_callback(void *args);
    
 private:
    unsigned char *image;
    int image_size;
    Color_t background;
    unsigned int event_mask;
    event_defaults (*menu_callback) (void *);
    watch_menu *parent;
    watch_menu *child;
 };
 
 
 
 
 #endif
