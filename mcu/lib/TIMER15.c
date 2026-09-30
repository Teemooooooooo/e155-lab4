// duration
#include "TIMER15.h"
#include "TIMER16.h"
#include "C:\Users\ellyu\Documents\GitHub\e155-lab4\mcu\lib\STM32L432KC_GPIO.h"

void setupTIM15(uint32_t psc_val) {
    // clear ARR
    TIM15->ARR = 0b0;

    // set PSC
    TIM15->PSC = psc_val; 

    // Clear then set UG bit 
    TIM15->EGR &= ~(1<<0);
    TIM15->EGR |= (1<<0);

    // Clear SR.UFI
    TIM15->SR &= ~(1<<0);

    // enable the counter within the timers
    TIM15->CR1 |= 0b1;
    
}

void playDuration(int note_freq, int duration, int pin) {
      // clear ARR
        TIM15->ARR = 0b0;
      // set ARR
        //duration / (prescalar + 1) * clk_freq
        // duration is in mili sec cancel with 3 zeros on the clk_freq
        TIM15->ARR = (duration *80000/ 8000);
      // Reset using EGR.UG
        TIM15->EGR |= (1<<0);
    // clear SR.UIF
        TIM15->SR &= ~(1<<0);

        TIM15->CR1 |= 0b1;
    
}
