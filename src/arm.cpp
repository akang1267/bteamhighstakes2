#include "arm.hpp"
#include "constants.hpp"
#include <cstdint>
#include "lemlib/pid.hpp"
#include "PID.hpp"

Arm::Arm(int8_t port, int8_t port2, int8_t port3) 
: armMotor1{port}, armMotor2{port2}, rotationalSensor{port3}
{}; 

// Function to perform PID control
double lift_target = 30;
auto lift_control = PID(4.5,0,11); //tune values

void Arm::reset(){
    rotationalSensor.reset_position();
    rotationalSensor.reset();
    //reset lift PID
    lift_control.reset();
}

void Arm::setArmHeight(double height){
    lift_target = height;
}
double prev_lift_pos;

void Arm::armTask(){
            double error_margin = 5;
            double lift_pos = rotationalSensor.get_position()/100;
            double calculatePower = lift_control.update(((lift_target - lift_pos)) + error_margin);
            armMotor1.move(calculatePower);
            armMotor2.move(calculatePower);
            if(fabs(lift_target - lift_pos)<= 2){
                calculatePower = lift_control.update((lift_pos- prev_lift_pos) + error_margin);
                armMotor1.move(calculatePower);
                armMotor2.move(calculatePower);
            }
            prev_lift_pos = lift_pos;
            
}
    


void Arm::stop(){
    armMotor1.brake();
    armMotor2.brake();
}

int32_t Arm::g_angle(){
    return rotationalSensor.get_position();
}

void Arm::set_voltage(int32_t voltage){
    armMotor1.move_voltage(voltage);
    armMotor2.move_voltage(voltage);
}
void Arm::move_up_middle(){
    if(rotationalSensor.get_position() < 3650){
        armMotor1.move_voltage(constants::ARM_VOLT);
        armMotor2.move_voltage(constants::ARM_VOLT);
    }
    else{
        armMotor1.brake();
        armMotor2.brake();
    }

}

void Arm::reach_up(){
    if(rotationalSensor.get_position() < 17500){
        armMotor1.move_voltage(constants::ARM_VOLT);
        armMotor2.move_voltage(constants::ARM_VOLT);
    }
    else{
        armMotor1.brake();
        armMotor2.brake();
        done = true;
    }
}

void Arm::back_to_rest(){
    if(rotationalSensor.get_position() > 3500){
        armMotor1.move_voltage(-constants::ARM_VOLT);
        armMotor2.move_voltage(-constants::ARM_VOLT);
    }
    else{
        armMotor1.brake();
        armMotor2.brake();
    }
}