/**
 * @brief main application entry point 
 */
#include "gym_watch.h"
#include "gym_menu.h"
#include "gym_ihm.h"
#include "gym_ihm_input.h"
#include "heart_rate_app.h"
#include "gym_exercise_counter.h"
#include "gym_pedometer.h"

watch_ihm main_ihm(PTB22,PTB21,PTC13,PTB20,PTE6,PTD15);
ihm_input main_input(PTE24, PTE25);

/* set the applications of our watch */
hr_app	main_hr_app;
pedometer_app pedometer;
gym_exercise exercises;


/** hackster logo */
extern int hackster_size;
extern const unsigned char hackster_img[];

extern int mbed_size;
extern const unsigned char mbed_img[];

extern int hexi_size;
extern const unsigned char hexi_img[];


/* power supply default state */
DigitalOut ldo(PTA29, 0x01);
DigitalOut sensors(PTB12, 0x00);
DigitalOut boost_en(PTC13, 0x01);


/**
 * @brief main application function 
 */
int main(void) 
{
	main_ihm.DimScreenOFF();
	main_ihm.FillScreen(COLOR_BLACK);


    /* Draw the hexiwear logo */
    main_ihm.DrawScreen(&hexi_img[0],0,0,96,96, OLED_TRANSITION_NONE);
    /* wait a bit */
    Thread::wait(2000);
    

    /* Draw the mbed logo */
    main_ihm.DrawScreen(&mbed_img[0],0,0,96,96, OLED_TRANSITION_NONE);
    /* wait a bit */
    Thread::wait(2000);



    main_hr_app.hr_start();
    pedometer.pedometer_app_start();
    exercises.gym_exercise_start();

    /*
     * Adds to the ihm the watch sub applications
     * menu and its options
     */
    main_ihm.watch_ihm_add_menu(main_hr_app.get_hr_menu());
    main_ihm.watch_ihm_add_menu(pedometer.get_pedometer_menu());
    main_ihm.watch_ihm_add_menu(exercises.gym_exercise_get_menu());

    /* starts the IHm manager */
    main_ihm.watch_ihm_start();

    /* links ihm manager with hw input channel */
    main_input.attach_thread(main_ihm.watch_ihm_get_input_channel());

    /* start the hw channel */
    main_input.ihm_input_start();

    /* todo adds a exeception exit */
    return 0;
}

