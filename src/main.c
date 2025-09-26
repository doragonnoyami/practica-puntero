#include "practica.h"
#include "stm32f103xb.h"
#define PUL 1

int main(void){
    gpio_on_off_t ledInterno;
    ledInterno.puerto = GPIOC;
    ledInterno.pin = 13;

    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN|RCC_APB2ENR_IOPBEN;
    ledInterno.puerto -> CRH &=~(0xF<<((ledInterno.pin%8)*4));
    ledInterno.puerto -> CRH |= (0x1<<((ledInterno.pin%8)*4));
    GPIOB -> CRL &=~(0xF<<(PUL*4));
    GPIOB -> CRL |= (0x8<<(PUL*4));
    GPIOB -> BSRR |= (1<<PUL);
    while(1){
        if(GPIOB->IDR&(1<<PUL)) {
            ledInterno.estPin = 1;
        }
        else {
            ledInterno.estPin = 0;
        }
        gpio_on_off(&ledInterno);
    }
    return 0;
}