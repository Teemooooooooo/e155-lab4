// Ellen Yu ellyu@g.hmc.edu Sep.27 2026
// main c file

// Includes for libraries
#include "../lib/STM32L432KC_RCC.h"
#include "../lib/STM32L432KC_GPIO.h"

// Define macros for constants

#define LED_PIN              3
#define DELAY_DURATION_MS    500

// Function for dummy delay by executing nops
void ms_delay(int ms) {
   while (ms-- > 0) {
      volatile int x=1000;
      while (x-- > 0)
         __asm("nop");
   }
}

int main(void) {
    // Turn on clock to GPIOB
    RCC->AHB2ENR |= (1 << 1);

    // Set LED_PIN as output
    pinMode(LED_PIN, GPIO_OUTPUT);

    // Blink LED
    while(1) {
        ms_delay(DELAY_DURATION_MS);
        togglePin(LED_PIN);
    }
    return 0;
}