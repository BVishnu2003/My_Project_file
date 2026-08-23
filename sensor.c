#include "sensor.h"
#include "adc.h"
#include "config.h"
#include "lcd.h"
#include "timer.h"


/* =========================================================
   LM35 TEMPERATURE SENSOR

   LM35 output:
   10 mV / degree Celsius

   Example:
   0.30 V = 30 degrees C

   ADC voltage:
   Voltage = ADC_Value * VREF / 4095

   Temperature:
   Temperature = Voltage * 100
   ========================================================= */

float Read_Temperature(void)
{
    unsigned int adcValue;
    float voltage;
    float temperature;

    adcValue = MCP3204_Read(TEMP_CHANNEL);

    voltage = ((float)adcValue * ADC_VREF)
              / ADC_MAX_VALUE;

    temperature = voltage * 100.0f;

    return temperature;
}




/* =========================================================
   SOIL MOISTURE SENSOR

   MCP3204 CH2 -> Soil moisture sensor

   Higher ADC value = more moisture
   ========================================================= */

unsigned int Read_SoilMoisture(void)
{
    unsigned int adcValue;
    unsigned int moisture;

    /* Read MCP3204 channel 2 */
    adcValue = MCP3204_Read(SOIL_CHANNEL);

    /* Convert ADC reading to percentage */
    moisture = (adcValue * 100UL) / 4095UL;

    /* Limit to 100% */
    if (moisture > 100)
    {
        moisture = 100;
    }

    return moisture;
}


/* =========================================================
   RAIN SENSOR

   MCP3204 CH1 -> Rain sensor
   ========================================================= */

unsigned int Read_RainSensor(void)
{
    unsigned int adcValue;
    unsigned int rain;

    /* Read MCP3204 channel 1 */
    adcValue = MCP3204_Read(RAIN_CHANNEL);

    /* Convert ADC reading to percentage */
    rain = (adcValue * 100UL) / 4095UL;

    if (rain > 100)
    {
        rain = 100;
    }

    return rain;
}


/* =========================================================
   LDR / LIGHT SENSOR

   MCP3204 CH3 -> LDR

   Higher ADC value = brighter light
   ========================================================= */

unsigned int Read_Light(void)
{
    unsigned int adcValue;
    unsigned int light;

    /* Read MCP3204 channel 3 */
    adcValue = MCP3204_Read(LDR_CHANNEL);

    /* Convert ADC reading to percentage */
    light = (adcValue * 100UL) / 4095UL;

    if (light > 100)
    {
        light = 100;
    }

    return light;
}


/* =========================================================
   DISPLAY SENSOR DATA
   ========================================================= */

void Display_SensorData(SensorData *data)
{
    /* =====================================================
       SCREEN 1

       TEMP:32.50C
       SOIL:65%
       ===================================================== */

    LCD_Clear();

    LCD_String("TEMP:");

    LCD_PrintFloat(data->temperature);

    LCD_Data('C');

    LCD_SetCursor(2, 1);

    LCD_String("SOIL:");

    LCD_PrintNumber(data->soilMoisture);

    LCD_Data('%');

    /* Wait 2 seconds */
    Timer0_Delay_ms(2000);


    /* =====================================================
       SCREEN 2

       RAIN:45%
       LIGHT:80%
       ===================================================== */

    LCD_Clear();

    LCD_String("RAIN:");

    LCD_PrintNumber(data->rainfall);

    LCD_Data('%');

    LCD_SetCursor(2, 1);

    LCD_String("LIGHT:");

    LCD_PrintNumber(data->light);

    LCD_Data('%');

    /* Wait 2 seconds */
    Timer0_Delay_ms(2000);
}
