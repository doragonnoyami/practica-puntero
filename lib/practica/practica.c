#include "practica.h"
#include "stm32f103xb.h"
#include "stdint.h"
/*
    pin elegido = es una variable que toma todos los valores de las variables de la estructura de tipos
    de datos.
    con la flechita tomo el valor de una variable de la estructura de tipos de datos
    con el punto escribo el valor en una variable de la estructura de tipos de datos
    el _t es una sintaxis general utilizada para diferenciar una nueva variable en la
    estructura de tipos de datos
*/
void gpio_on_off(gpio_on_off_t* pinElegido){
    if( pinElegido->estPin){
        pinElegido->puerto -> BSRR |=(1<<pinElegido->pin);
    }
    else{ 
        pinElegido->puerto -> BSRR |=(1<<(pinElegido->pin+16));
    }
}