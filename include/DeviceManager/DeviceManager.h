#ifndef DISPLAYMANAGER
#define DISPLAYMANAGER

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "ButtonManager/Button.h"
#include <RTClib.h>




struct Device {
    String device_name;
    int device_pin;
    bool is_active; // flag control output rele
    int delay_automatic_active; // interval for next activation in hours
    int opening_hours;   // 0-> full-time // 1-> only-day // 2-> only-night
    
    int flow_rate; // open valve visibly in display

    DateTime next_active; // next time for active device
    DateTime last_active;
    DateTime now_active;
  };





class DeviceManager 
{
  

  public:
    LiquidCrystal_I2C lcd;
    RTC_DS3231 rtc;
    DeviceManager(Device* devices);
    

    bool is_changed();

    void rtc_init();


    void lcd_init();

    void devices_init();

    void view(bool state_long_pressed_action_btn ,bool action_button , bool rigth_button ,bool left_button);
    void devices_view();
    void config_device_view(bool active_button);



    void delayMessage(bool* flag);

    void handler(Button* action_button ,Button* rigth_button , Button* left_button);

    void updateSettingsDevice(int device_id);
    void verify_is_active();

    



  private:
    void verify_timers_and_update();
    
    Device* _devices;
    int _lengh_devices;

    String _MENU;
    int _DEVICE_SELECTED;
    bool _flag_active_message = false ;
    bool flag_changed;


};

#endif