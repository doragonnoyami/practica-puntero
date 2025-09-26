#ifndef PUNTO2_H
#define PUNTO2_H
#include <stdint.h>
#include "stm32f103xb.h"
typedef struct {
    GPIO_TypeDef* puerto;
    int pin;
    char modo;
    int estPin;
}pin_t;

void clocks(pin_t*);
void conf(pin_t*);
void write(pin_t*);
int read(pin_t*);
#endif