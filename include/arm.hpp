#pragma once
#include "api.h"
#include <string>

class Arm {
    private:
    

    public:

    int32_t state = 0;
    int32_t prev = 0;
    bool done = false;

    // double Kp = 0.8;  // Proportional constant
    // double Ki = 0.1;  // Integral constant
    // double Kd = 0.2;  // Derivative constant
    // double setpoint = 0;  // Desired position (could be in degrees, rotations, etc.)
    // double lastError = 0;  // Previous error, used for derivative calculation
    // double integral = 0;  // Integral sum

    pros::Motor armMotor1;
    pros::Motor armMotor2;
    pros::Rotation rotationalSensor;


    Arm(int8_t port, int8_t port2, int8_t port3);
    //void pidControl();
    void update();
    void reset();
    void stop();
    void set_voltage(int32_t voltage);
    void armTask();
    void setArmHeight(double height);
    int32_t g_angle();

};