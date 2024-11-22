#pragma once
#include "api.h"
#include "Intake.hpp"
#include "Pneumatics.hpp"
#include "arm.hpp"
#include "constants.hpp"
#include <vector>
#include "lemlib/api.hpp"
extern Intake intake;
extern Pistons mogo; 
extern Pistons hang;
extern Pistons doinker;
extern Arm arm;

extern lemlib::Chassis chassis;
class Robot {
    private:
        pros::Controller m_controller {pros::E_CONTROLLER_MASTER}; 
        // Robot components 
        Intake intake; 
        Pistons mogo, hang, doinker;
        Arm arm;

        // Update component functions 
        void update_intake();
        void update_mogo();
        void update_hang();
        void update_doinker();
        void update_arm();
        void update_drivetrain();

    public: 

        // overall update function 
        void update(); 

        // constructor 
        Robot(Intake intake, Pistons mogo, Pistons hang, Pistons doinker, Arm arm);  
};
extern Robot robot;