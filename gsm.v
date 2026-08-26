#include <LPC21xx.h>
#include "uart.h"
#include "gsm.h"
#include "timer.h"

void GSM_INIT(void)
{
    UART0_STRING("AT\r\n");
    Timer0_Delay_ms(1000);

    UART0_STRING("AT+CMGF=1\r\n");
    Timer0_Delay_ms(1000);
}

void GSM_SEND_SMS(char *message)
{
    /* Set SMS text mode */
    UART0_STRING("AT+CMGF=1\r\n");
    Timer0_Delay_ms(1000);

    /* Enter receiver number */
    UART0_STRING("AT+CMGS=\"6381880287\"\r\n");
    Timer0_Delay_ms(1000);

    /* Send SMS message */
    UART0_STRING(message);

    /* CTRL+Z to send */
    UART0_TX(26);

    Timer0_Delay_ms(3000);
}


