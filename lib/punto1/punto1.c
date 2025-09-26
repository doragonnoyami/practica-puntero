#include "punto1.h"
#include "stm32f103xb.h"
void clocks(conf_t* pinElegido){//Elegimos clock
    if((pinElegido->puerto)==GPIOA){
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    }
    if((pinElegido->puerto)==GPIOB){
        RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    }
    if((pinElegido->puerto)==GPIOC){
        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    }
}
void conf(conf_t* pinElegido){//Configuramos el modo
    if(pinElegido->pin <8){
        pinElegido->puerto -> CRL &=~(0xF<<(pinElegido->pin*4));
        pinElegido->puerto -> CRL |=(pinElegido->modo << (pinElegido->pin*4));
    }
    else if(pinElegido->pin >=8){
        pinElegido->puerto -> CRH &=~(0xF<<((pinElegido->pin%8)*4));
        pinElegido->puerto -> CRH |=(pinElegido->modo << ((pinElegido->pin%8)*4));
    }
}
void write(conf_t* pinElegido){//Escribimos el valor
    if(pinElegido->estPin){
        pinElegido->puerto -> BSRR |=(1<<pinElegido->pin);
    }else{
        pinElegido->puerto -> BSRR |=(1<<(pinElegido->pin+16));
    }
}
int read(conf_t* pinElegido){//Lectura del valor
    if(pinElegido->puerto->IDR&(1<<pinElegido->pin)){
        return 1;
    }else{
        return 0;
    }
}

