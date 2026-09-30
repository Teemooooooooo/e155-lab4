// Ellen Yu ellyu@g.hmc.edu Sep.27 2026
// main c file

// Includes for libraries
#include "C:\Users\ellyu\Documents\GitHub\e155-lab4\mcu\lib\STM32L432KC_FLASH.h"
#include "C:\Users\ellyu\Documents\GitHub\e155-lab4\mcu\lib\STM32L432KC_RCC.h"
#include "C:\Users\ellyu\Documents\GitHub\e155-lab4\mcu\lib\TIMER15.h"
#include "C:\Users\ellyu\Documents\GitHub\e155-lab4\mcu\lib\TIMER16.h"
#include "C:\Users\ellyu\Documents\GitHub\e155-lab4\mcu\lib\STM32L432KC_GPIO.h"

// Define macros for constants

#define LED_PIN              3
#define DELAY_DURATION_MS    500


// Pitch in Hz, duration in ms
//const int notes[][2] = {
//{659,	125},
//{623,	125},
//{659,	125},
//{623,	125},
//{659,	125},
//{494,	125},
//{587,	125},
//{523,	125},
//{440,	250},
//{  0,	125},
//{262,	125},
//{330,	125},
//{440,	125},
//{494,	250},
//{  0,	125},
//{330,	125},
//{416,	125},
//{494,	125},
//{523,	250},
//{  0,	125},
//{330,	125},
//{659,	125},
//{623,	125},
//{659,	125},
//{623,	125},
//{659,	125},
//{494,	125},
//{587,	125},
//{523,	125},
//{440,	250},
//{  0,	125},
//{262,	125},
//{330,	125},
//{440,	125},
//{494,	250},
//{  0,	125},
//{330,	125},
//{523,	125},
//{494,	125},
//{440,	250},
//{  0,	125},
//{494,	125},
//{523,	125},
//{587,	125},
//{659,	375},
//{392,	125},
//{699,	125},
//{659,	125},
//{587,	375},
//{349,	125},
//{659,	125},
//{587,	125},
//{523,	375},
//{330,	125},
//{587,	125},
//{523,	125},
//{494,	250},
//{  0,	125},
//{330,	125},
//{659,	125},
//{  0,	250},
//{659,	125},
//{1319,	125},
//{  0,	250},
//{623,	125},
//{659,	125},
//{  0,	250},
//{623,	125},
//{659,	125},
//{623,	125},
//{659,	125},
//{623,	125},
//{659,	125},
//{494,	125},
//{587,	125},
//{523,	125},
//{440,	250},
//{  0,	125},
//{262,	125},
//{330,	125},
//{440,	125},
//{494,	250},
//{  0,	125},
//{330,	125},
//{416,	125},
//{494,	125},
//{523,	250},
//{  0,	125},
//{330,	125},
//{659,	125},
//{623,	125},
//{659,	125},
//{623,	125},
//{659,	125},
//{494,	125},
//{587,	125},
//{523,	125},
//{440,	250},
//{  0,	125},
//{262,	125},
//{330,	125},
//{440,	125},
//{494,	250},
//{  0,	125},
//{330,	125},
//{523,	125},
//{494,	125},
//{440,	500},
//{  0,	0}};

const int notes[][2] = {
{294,	250},
{392,	250},
{587,	250},
{294,	250},
{392,	250},
{587,	250},
{294,	250},
{392,	250},
{587,	250},
{  0,	250},
{  0,	1500},
{294,	250},
{392,	250},
{587,	250},
{294,	250},
{392,	250},
{587,	250},
{294,	250},
{392,	250},
{587,	250},
{294,	250},
{392,	250},
{587,	250},
{294,	250},
{392,	250},
{698,	500},
{587,	250},

{294,	250},
{392,	250},
{587,	250},
{294,	250},
{392,	250},
{587,	250},
{294,	250},
{392,	250},
{587,	250},
{  0,	0}
};


int main(void) {
    configureFlash();
    configureClock();
    // enable TIM15 and TIM16
    RCC->APB2ENR |= (0b11 << 16);



    // Turn on clock to GPIOB
    RCC->AHB2ENR |= (1 << 1);

    // Set LED_PIN as output (note output)
    pinMode(LED_PIN, GPIO_OUTPUT);
    
    const int psc = 79;
    setupTIM15(7999);
    setupTIM16(psc);
    // setting up the loop
    int num_notes = sizeof(notes)/ sizeof(notes[0]);   
    // play note
    // note_freq would be notes[i][0]
    // duration would be notes[i][1]

    // _______________________ DEBUG________________________
//    while(1){
//        playPitch(659, 3);
//        // wait for SR.UIF to be 1
//        while(!((TIM16->SR) & 1));
//        // flip the output
//        togglePin(3); // know what the LED is later
//        // Clear SR.UFI
//        TIM16->SR &= ~(1<<0);

//}


    for(int i=0; i < num_notes; i++) {
        playDuration(notes[i][0],notes[i][1], LED_PIN);
        while(!((TIM15->SR) & 1)){
          if (notes[i][0] != 0){          
            playPitch(notes[i][0], 3);
            // wait for SR.UIF to be 1
            while(!((TIM16->SR) & 1));
            // flip the output
            togglePin(3); // know what the LED is later
            // Clear SR.UFI
            TIM16->SR &= ~(1<<0);
          }else {
            // OUTPUT = 0
            digitalWrite(3, 0);
        };
  
      }
      // Clear SR.UFI
        TIM15->SR &= ~(1<<0);
    }
    return 0;
}