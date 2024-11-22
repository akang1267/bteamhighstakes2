#include "Robot.hpp"
#include "intake.hpp"
#include "arm.hpp"
#include "main.h"
#include "pros/optical.hpp"
#include "pros/rtos.hpp"
#include "ports.hpp"
#include "lemlib/api.hpp"

//robot config
pros::MotorGroup left_mg({ports::LEFTFRONT,ports::LEFTMIDDLE, ports::LEFTBACK}, pros::MotorGearset::blue);    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
pros::MotorGroup right_mg({ports::RIGHTFRONT, ports::RIGHTMIDDLE, ports::RIGHTBACK}, pros::MotorGearset::blue);  // Creates a motor group with forwards port 5 and reversed ports 4 & 6
// drivetrain settings
lemlib::Drivetrain drivetrain(&left_mg, // left motor group
                              &right_mg, // right motor group
                              11.5, // 12.5 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
                              480, // drivetrain rpm is 480
                              8 // horizontal drift is 2 (for now)
);
pros::Imu imu(ports::INERT);

lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                           	nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

lemlib::ControllerSettings lateral_controller(9, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              0, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              2, // large error range, in inches
                                              200, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)

);

// angular PID controller
lemlib::ControllerSettings angular_controller(18, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              9, // derivative gain (kD)
                                              0, // anti windup
                                              1, // small error range, in inches
                                              50, // small error range timeout, in milliseconds
                                              2, // large error range, in inches
                                              100, // large error range timeout, in milliseconds
                                              0 // maximum acce
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttleCurve, &steerCurve);

Intake intake = Intake {ports::INTAKE, ports::HOOK_CON, ports::OPTICAL_PORT};
Pistons mogo = Pistons {ports::MOGO_CLAMP,ports::HANG_PORT, ports::DOINKER, false, false, false}; 
Pistons hang = Pistons {ports::MOGO_CLAMP,ports::HANG_PORT, ports::DOINKER, false, false, false};
Pistons doinker = Pistons {ports::MOGO_CLAMP,ports::HANG_PORT, ports::DOINKER, false, false, false};
Arm arm = Arm {ports::ARM1, ports::ARM2, ports::ROTAT_PORT};
Robot robot = Robot {intake, mogo, hang, doinker, arm};


Robot::Robot(Intake intake_in, Pistons mogo, Pistons hang, Pistons doinker, Arm arm)
: intake {intake_in}, mogo {mogo}, hang {hang}, doinker {doinker}, arm {arm}
{}; 




// NEED TO UPDATE
void Robot::update_intake() { 
    int8_t R1_pressed = m_controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1);
    int8_t R1_pressing = m_controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);  
    
    int8_t R2_pressed = m_controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2);
    int8_t R2_pressing = m_controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);

    if(R1_pressing) {
        intake.set_voltage(constants::INTAKE_VOLT);
        double hue = intake.opticalSensor.get_hue();
        // if ((hue >= 0 && hue <= 20) || (hue >= 340 && hue <= 360)) {
        //     pros::lcd::print(3, "Red Detected"); // y
        //     intake.set_voltage(constants::INTAKE_STOP);
        //     intake.set_voltage(constants::INTAKE_STOP);
        //     intake.set_voltage(constants::INTAKE_STOP);
        //     intake.set_voltage(constants::INTAKE_STOP);
        //     intake.set_voltage(constants::INTAKE_STOP);
        //     intake.set_voltage(constants::INTAKE_VOLT);
        // }
        // else{
        //     intake.set_voltage(constants::INTAKE_VOLT);
        // }
    }


    else if(R2_pressing){
        intake.set_voltage(-constants::INTAKE_VOLT);
    }

    else {
        intake.set_voltage(0);
    }
}

void Robot::update_arm(){

    int8_t A_pressed = m_controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A);
    int8_t A_pressing = m_controller.get_digital(pros::E_CONTROLLER_DIGITAL_A);

    int8_t X_pressed = m_controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X);
    int8_t X_pressing = m_controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);

    int8_t B_pressed = m_controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B);
    int8_t L1_pressing = m_controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);

    
    arm.armMotor1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    arm.armMotor2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    
    if(X_pressed && (arm.state == 0)){
        arm.state = 1;
    }
    else if(X_pressed && (arm.state == 1)){
        arm.state = 0;
        arm.prev = 1;
    }
    else if(L1_pressing && (arm.state == 1)){
        arm.state = 2;
        arm.prev = 1;
    }
    else if((arm.state == 2) && arm.done){
        arm.done = false;
        arm.state = 0;
        arm.prev = 2;
    }
    
    if(arm.state == 1){
        arm.setArmHeight(39.12);
    }
    if(arm.state == 2){
        arm.setArmHeight(168.21);
        if(!L1_pressing){
            arm.state = 0;
        }
    }
    if(arm.state == 0){
        if(arm.prev == 1){
            arm.setArmHeight(27.58);
        }
        else if(!L1_pressing){
            arm.setArmHeight(25.58);
        }
    }

}

void Robot::update_mogo(){
    int8_t A_pressed = m_controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A);

    if(A_pressed){
        mogo.toggle_mogo_clamp();
    }
}

void Robot::update_hang(){
    int8_t Y_pressed = m_controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y);
    
    if(Y_pressed){
        hang.toggle_hang();
    }
    
}

void Robot::update_doinker(){
    int8_t L2_pressing = m_controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
    

    if(L2_pressing && !doinker.doinker_state){
        doinker.toggle_doinker();
    }
    if(doinker.doinker_state && !L2_pressing){
            doinker.toggle_doinker();
        }
}

void Robot::update() {
    update_intake();
    update_mogo();
    update_hang();
    update_doinker();
    update_arm();
    
}