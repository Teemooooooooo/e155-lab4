// pitch

#include "TIMER16.h"
#include "STM32L432KC_GPIO.h"

void setupTIM16(uint32_t psc_val) {
    //// clear ARR
    //TIM16->ARR = 0b0;

    //// set PSC
    //TIM16->PSC = psc_val; 

    //// Clear then set UG bit 
    //TIM16->EGR &= ~(1<<0);
    //TIM16->EGR |= (1<<0);

    //// clear SR.UIF
    //TIM16->SR &= ~(1<<0);
    //// enable the counter within the timers
    //TIM16->CR1 |= 0b1;
    // 
}

void playPitch(uint32_t note_freq, int pin) {
    //// clear ARR
    //TIM16->ARR = 0b0;
    //// rest otherwise
    //if (note_freq != 0) {
            
    //    // set ARR
    //    // divide ARR by two so frequency doubles
    //    // (clk_freq / (prescalar+1) / pitch_freq / 2 )- 1
    //    TIM16->ARR = (80000000/80/(note_freq *2))- 1; // TODO
    //    // Reset using EGR.UG
    //    TIM16->EGR |= (1<<0);
    //    // clear SR.UIF
    //    TIM16->SR &= ~(1<<0);
    //    // wait for SR.UIF to be 1
    //    while(~((TIM16->SR) & 1));
    //    // flip the output
    //    togglePin(pin); // know what the LED is later
            
    //    // Clear SR.UFI
    //    TIM16->SR &= ~(1<<0);
    //}else {
    //    // OUTPUT = 0
    //    digitalWrite(pin, 0);
    //}
}
