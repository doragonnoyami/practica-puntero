#ifndef PUNTO1_H
#define PUNTO1_H
#include <stdint.h>
#include "stm32f103xb.h"
typedef struct {
    GPIO_TypeDef* puerto;
    int pin;
    char modo;
    int estPin;
}conf_t;
void clocks(conf_t*);
void conf(conf_t*);
void write(conf_t*);
int read(conf_t*);
#endif