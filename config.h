#ifndef CONFIG_H
#define CONFIG_H

#include <LPC21xx.h>

/* =========================================================
   LPC2129 Weather Monitoring System
   Configuration File
   ========================================================= */

/* CPU Clock */
#define FOSC                12000000UL
#define CCLK                60000000UL


/* =========================================================
   MCP3204 ADC Channels
   ========================================================= */

#define TEMP_CHANNEL       0
#define RAIN_CHANNEL       1       /* No longer used - IR used */
#define SOIL_CHANNEL       2
#define LDR_CHANNEL        3

/* MCP3204 Reference Voltage */
#define ADC_VREF           3.3f

/* MCP3204 Resolution */
#define ADC_MAX_VALUE      4095.0f


/* =========================================================
   IR RAIN SENSOR
   ========================================================= */

/* IR sensor OUT connected to LPC2129 P0.14 */
#define IR_SENSOR_PIN      18


/* =========================================================
   Sensor Thresholds
   ========================================================= */

/* Temperature in Celsius */
#define TEMP_HIGH_LIMIT    35.0f

/* Soil moisture percentage */
#define SOIL_LOW_LIMIT     30

/* Rain sensor percentage - NOT USED with IR */
#define RAIN_LIMIT         30

/* Light intensity percentage */
#define LIGHT_LOW_LIMIT    20


/* =========================================================
   GSM Configuration
   ========================================================= */

/* Change this to the actual receiver number */
#define PHONE_NUMBER       "9876543210"

/* GSM UART baud rate */
#define GSM_BAUDRATE       9600


/* =========================================================
   Monitoring Interval
   ========================================================= */

#define SENSOR_INTERVAL_MS 5000


/* =========================================================
   GPIO Definitions
   ========================================================= */

/* LED */
#define LED_ON             1
#define LED_OFF            0

/* Buzzer */
#define BUZZER_ON          1
#define BUZZER_OFF         0


/* =========================================================
   System Status
   ========================================================= */

#define NORMAL_STATUS      0
#define ALERT_STATUS       1

#endif
