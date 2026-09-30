// duration
#include "TIMER15.h"
#include "TIMER16.h"


void setupTIM15(uint32_t psc_val) {
    //// clear ARR
    //TIM15->ARR = 0b0;

    //// set PSC
    //TIM15->PSC = psc_val; 

    //// Clear then set UG bit 
    //TIM15->EGR &= ~(1<<0);
    //TIM15->EGR |= (1<<0);

    //// Clear SR.UFI
    //TIM15->SR &= ~(1<<0);

    //// enable the counter within the timers
    //TIM15->CR1 |= 0b1;
    
}

void playDuration(int note_freq, int duration, int pin) {
    //// Repeat until SR.UIF is 1
    //while(~((TIM15->SR) & 1)){
    //    // clear ARR
    //    TIM15->ARR = 0b0;

    //    // set ARR
    //    //duration / (prescalar + 1) * clk_freq
    //    // duration is in mili sec cancel with 3 zeros on the clk_freq
    //    TIM15->ARR = (duration *80000/ 80);
    //    // Reset using EGR.UG
    //    TIM15->EGR |= (1<<0);

    //    playPitch(note_freq, pin);

    //}

    //// Clear SR.UFI
    //TIM15->SR &= ~(1<<0);
}
