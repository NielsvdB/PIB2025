/**
 * @file main.c
 * @author Niels
 * @date 2026-01-05
 * @brief Main function
 */
 #include <avr/io.h>
int main(){
    PORTA.DIR |= 0x0F;
    while(1){
        // Main loop code here
         PORTB.OUT ^= 0x0F; // Toggle lower nibble of PORTB
         for(volatile uint32_t i = 0; i < 100000; i++); // Simple delay
    }

    return 0;
}
