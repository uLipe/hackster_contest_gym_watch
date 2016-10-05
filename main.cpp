/**
 * @brief main application entry point 
 */
#include "gym_watch.h"
#include "gym_menu.h"
#include "gym_ihm.h"
#include "gym_ihm_input.h"
#include "heart_rate_app.h"


watch_ihm main_ihm(PTB22,PTB21,PTC13,PTB20,PTE6,PTD15);
//ihm_input main_input(PTE24, PTE25);
hr_app	main_hr_app;



/* powe supply default state */
DigitalOut ldo(PTA29, 0x01);
DigitalOut sensors(PTB12, 0x00);
DigitalOut boost_en(PTC13, 0x01);


/**
 * @brief main application function 
 */
int main(void) 
{
    /* Draw the hexiwear logo */
    
    /* wait a bit */
    Thread::wait(3000);
    
    main_hr_app.hr_start();
    main_ihm.watch_ihm_add_menu(main_hr_app.get_hr_menu());
  //  main_input.ihm_input_start();
    main_ihm.watch_ihm_start();
}

