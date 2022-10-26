#include <Arduino.h>
#include "DeviceManager/DeviceManager.h"
#include "ButtonManager/Button.h" 
#include <EEPROM.h>

Button ActiveButton(2), RightButton(3), LeftButton(4);


Device devices[] = {
  {
    .device_name = "Valvula 1",
    .device_pin = 13,
  },
  {
    .device_name = "Valvula 2",
    .device_pin = 12,
  },
    {
    .device_name = "Valvula 3",
    .device_pin = 11,
  }
};


DeviceManager device(devices);

void setup() 
{
  Serial.begin(9600);
  device.lcd_init();
  device.rtc_init();
  device.devices_init();
}

void loop() 
{
  device.handler(&ActiveButton , &RightButton ,&LeftButton );
  delay(4);
}
