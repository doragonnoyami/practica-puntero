#ifndef PRACTICA_H
#define PRACTICA_H
#include <stdint.h> //para mas tipos de variables
#include "stm32f103xb.h"
typedef struct {
GPIO_TypeDef* puerto; // Qué puerto es
unsigned int pin; // Número de pin
unsigned int estPin; // Estado del pin
} gpio_on_off_t;
void gpio_on_off(gpio_on_off_t*);
#endif