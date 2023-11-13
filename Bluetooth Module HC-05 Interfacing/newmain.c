#include <xc.h>
#include <stdint.h>
#include "config.h"
#define _XTAL_FREQ 4000000

uint8_t UART_BUFFER = 0;
void UART_init(void){
    TRISC6 = 1; TRISC7 = 1;
    BRGH = 1;
    SPBRG = 25;//baud rate 9600 bps
    SYNC = 0;
    SPEN = 1;
    RCIE = 1;
    RCIF = 0;
    GIE = 1;
    PEIE = 1;
    CREN = 1;
}
void __interrupt() ISR(){
    if(RCIF){
        UART_BUFFER = RCREG;
        if(UART_BUFFER == 49) RB0 = 1;//convert from ascii to number because virtual terminal proteus
        if(UART_BUFFER == 50) RB0 = 0;///convert from ascii to number because virtual terminal proteus
        if(UART_BUFFER == 51) RB1 = ~RB1;//convert from ascii to number because virtual terminal proteus
        RCIF = 0;
    }
}
void main(void) {
    UART_init();
    TRISB0 = 0;
    TRISB1 = 0;
    RB0 = 0; RB1 = 0;
    while(1){
       
    }
    return;
}
