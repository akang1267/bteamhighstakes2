#include "intake.hpp"
#include "constants.hpp"
#include <cstdint>

Intake::Intake(int8_t port, int8_t port2, uint8_t port3) 
: intakeMotor{port}, hookMotor{port2}, opticalSensor{port3}
{}; 

void Intake::set_voltage(int32_t voltage){
    intakeMotor.move_voltage(voltage);
    hookMotor.move_voltage(voltage);
}

void Intake::toggle(int32_t voltage){
    intake_on = !intake_on;
    if (intake_on){
    intakeMotor.move_voltage(voltage);
    hookMotor.move_voltage(voltage);
    }
    else {
        intakeMotor.move_voltage(0);
        hookMotor.move_voltage(0);
    }
}

void Intake::intake_only_toggle(int32_t voltage){
    intake_only_on =!intake_only_on;
    if (intake_only_on){
        intakeMotor.move_voltage(voltage);
    }
    else{
        intakeMotor.move_voltage(0);
    }
}

void Intake::chain_toggle(int32_t voltage){
    hook_on = !hook_on;
    if (hook_on){
        hookMotor.move_voltage(voltage);
    }
    else{
        hookMotor.move_voltage(0);
    }
}


bool Intake::get_state() {
    return intake_on;
}