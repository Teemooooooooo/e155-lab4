// STM32L432KC_RCC.c
// Source code for RCC functions

#include "STM32L432KC_RCC.h"

void configurePLL(void) {
    // Set clock to 80 MHz
    // Output freq = (src_clk) * (N/M) / R
    // (4 MHz) * (N/M) / R = 80 MHz
    // M: XX, N: XX, R: XX
    // Use MSI as PLLSRC

    // Turn off PLL
    RCC->CR &= ~(1<<24);
    // Wait till PLL is unlocked (e.g., off)
    while ((RCC->CR >> 25) & 0b1);

    // Load configuration
    // TODO: Set PLL SRC to MSI
    RCC->PLLCFGR |= 1;
    RCC->PLLCFGR &= ~(1<<1); 

    // TODO: Set PLLN -> 1010000
    RCC->PLLCFGR &= ~(0b11111111 << 8); // clear PLLN bits
    RCC->PLLCFGR |= (0b1010000 << 8);  // set it to 80

    // TODO: Set PLLM -> 000
    RCC->PLLCFGR &= ~(0b111 << 4);

    // TODO: Set PLLR -> 01
    RCC->PLLCFGR &= ~(1 << 26);
    RCC->PLLCFGR |= (1 << 25);
    
    // TODO: Enable PLLR output
    RCC->PLLCFGR |= (1 << 24);

    // TODO: Enable PLL
    RCC->CR |= (1 << 24);
    
    // TODO: Wait until PLL is locked
    while ((RCC->CR >> 25 & 1) != 1);
}

void configureClock(void){
    // Configure and turn on PLL
    configurePLL();

    // Select PLL as clock source
    RCC->CFGR |= (0b11 << 0);
    while(!((RCC->CFGR >> 2) & 0b11));
}