#pragma once
#include "api.h"
#include <string>
class Intake {

private:
    pros::Motor intakeMotor;
    pros::Motor hookMotor; 
    bool intake_on = false; 
    bool intake_only_on = false;
    bool hook_on = false;   
    
   
    
public:
    bool colorDetected = false;
    pros::Optical opticalSensor;

    Intake(int8_t port, int8_t port2, uint8_t port3);
    void set_voltage(int32_t voltage);

    void switch_polarity();
    int8_t get_polarity(); 
    bool get_state();
    void detect_color();

    void toggle(int32_t voltage); 
    void intake_only_toggle(int32_t voltage);
    void chain_toggle(int32_t voltage);

};