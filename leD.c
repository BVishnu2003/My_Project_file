#include <LPC21xx.h>
#include "led.h"

#define LED_PIN 10

void LED_INIT(void)
{
    IODIR0 |= (1 << LED_PIN);
    IOCLR0 = (1 << LED_PIN);
}

void LED_HIGH(void)
{
    IOSET0 = (1 << LED_PIN);
}

void LED_LOW(void)
{
    IOCLR0 = (1 << LED_PIN);
}
