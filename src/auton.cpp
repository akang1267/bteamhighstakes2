#include "main.h"
#include "Robot.hpp"
#include "arm.hpp"
#include "auton.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep

double T = 24;

void blue_solo_awp(Intake intake, Pistons mogo, Pistons hang, Pistons doinker, Arm arm){
    chassis.setPose(0,0,0);

    doinker.toggle_doinker();
    pros::delay(400);
    //going to allliance stake
    chassis.turnToHeading(-90, 1000); 
    chassis.moveToPose(-6, -1.6, -121, 1000);
    doinker.toggle_doinker();
    chassis.moveToPose(5, 9, -100, 1000, {.forwards = false});
    chassis.waitUntilDone();
    pros::delay(200);
    intake.toggle(constants::INTAKE_VOLT);
    pros::delay(1000);
    intake.toggle(constants::INTAKE_STOP);

    //moving to mogo
    chassis.moveToPoint(0,8,1000, {.minSpeed = 127});
    chassis.turnToHeading(-142, 1000, {.minSpeed=127});
    intake.toggle(constants::INTAKE_VOLT);
    chassis.moveToPose(-7, -20, -190, 1000, {.lead = 0.6});
    chassis.waitUntil(17);
    intake.toggle(constants::INTAKE_STOP);
    chassis.turnToHeading(-313, 1000);
    chassis.moveToPoint(-18, -31,2300, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntil(15);
    mogo.toggle_mogo_clamp(); 
    chassis.waitUntilDone();
    intake.toggle(constants::INTAKE_VOLT);
    chassis.turnToHeading(-190, 1000);
    chassis.moveToPose(-16.5, -54, -190, 1000);


    chassis.moveToPose(-15, -37, -146, 1000, {.forwards = false});
    chassis.turnToHeading(-67, 1000);
    chassis.moveToPoint(-28, -32, 1000, {.maxSpeed = 50});
    mogo.toggle_mogo_clamp();
    
    chassis.moveToPose(8, -30, -454, 1000, {.forwards = false, .minSpeed = 127});
    chassis.turnToHeading(-590, 1000);
    chassis.moveToPose(12, -37, -578, 1000, {.minSpeed = 127});
    intake.toggle(constants::INTAKE_STOP);
    chassis.moveToPose(-18, -40, -633, 1000, {.forwards = false});
    mogo.toggle_mogo_clamp();
}


void red_solo_awp(Intake intake, Pistons mogo, Pistons hang, Pistons doinker, Arm arm){
    chassis.setPose(0,0,0);

    doinker.toggle_doinker();
    pros::delay(400);

    chassis.turnToHeading(70, 1000);

    chassis.moveToPose(-7.6, 10.8, 170, 1000, {.forwards = false});
    doinker.toggle_doinker();
    chassis.turnToHeading(72, 1000);
    chassis.moveToPoint(-12.5, 10, 1000, {.forwards = false, .maxSpeed = 30});
    chassis.waitUntilDone();
    intake.toggle(constants::INTAKE_VOLT);
    pros::delay(700);
    intake.toggle(constants::INTAKE_STOP);
    chassis.moveToPose(7, -10, 170, 1000);
    chassis.turnToHeading(260, 1000);
    chassis.moveToPoint(23, -10, 5000, {.forwards = false, .maxSpeed = 40});
    chassis.waitUntil(20);
    mogo.toggle_mogo_clamp();
    pros::delay(200);
    chassis.turnToHeading(337, 1000);
    chassis.moveToPoint(18, 5, 1000);
    intake.toggle(constants::INTAKE_VOLT);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(23, -5, 1000, {.forwards = false});
    chassis.turnToHeading(150, 1000);
    chassis.moveToPose(10, -24, 200, 1000);
    chassis.waitUntilDone();
    pros::delay(200);  
    chassis.turnToHeading(40, 1000);
    chassis.moveToPoint(33, -3, 10000, {.maxSpeed = 40,});
}

void tuning_pid(){
    chassis.setPose(0,0,0);

    //chassis.moveToPoint(0, 24, 4000);
    chassis.turnToHeading(90, 1000);
}
void red_rings_side(Intake intake, Pistons mogo, Pistons hang, Pistons doinker, Arm arm){
    chassis.setPose(0, 0, 0);

    //alliance stake
    chassis.moveToPoint(0, -17, 1000, {.forwards = false});
    chassis.turnToHeading(90, 1000);
    chassis.moveToPoint(-7.2, -18, 1000, {.forwards = false, .maxSpeed = 30});
    chassis.waitUntilDone();
    pros::delay(300);
    intake.toggle(constants::INTAKE_VOLT);
    pros::delay(1000);
    chassis.moveToPoint(-2, -18, 1000);
    intake.toggle(constants::INTAKE_STOP);

    //turn and move to mogo
    chassis.turnToHeading(240, 1000);
    chassis.moveToPose(38, 6, 245, 2000, {.forwards = false, .maxSpeed = 60});
    chassis.waitUntil(40);
    mogo.toggle_mogo_clamp();

    //to two ring stack back
    chassis.turnToHeading(350, 1000);
    intake.toggle(constants::INTAKE_VOLT);
    chassis.moveToPoint(3, 23, 1000);

    // //getting rings at midpoint
    chassis.turnToHeading(90, 1000);
    chassis.moveToPose(48, 24, 81, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(31, 32, 104, 2000, {.forwards = false});
    chassis.turnToHeading(80, 1000);
    chassis.moveToPoint(48, 34, 2000);
    chassis.waitUntilDone();

    //move
    chassis.moveToPose(27, 5, 24, 1000, {.forwards = false });
    chassis.turnToHeading(106, 1000);
    chassis.moveToPoint(47.4, 4, 1000, {.maxSpeed = 50});

}

void blue_rings_side(Intake intake, Pistons mogo, Pistons hang, Pistons doinker, Arm arm){
    chassis.setPose(0, 0, 0);

    //alliance stake
    chassis.moveToPoint(0, -17.35, 1000, {.forwards = false});
    chassis.turnToHeading(-90, 1000);
    chassis.moveToPoint(7.45, -18, 1000, {.forwards = false, .maxSpeed = 30});
    chassis.waitUntilDone();
    pros::delay(300);
    intake.toggle(constants::INTAKE_VOLT);
    pros::delay(1000);
    chassis.moveToPoint(2, -18, 1000);
    intake.toggle(constants::INTAKE_STOP);

    //turn and move to mogo
    chassis.turnToHeading(-240, 1000);
    chassis.moveToPose(-38, 8, -245, 2000, {.forwards = false, .maxSpeed = 60});
    chassis.waitUntil(40);
    mogo.toggle_mogo_clamp();

    //to two ring stack back
    chassis.turnToHeading(-341, 1000);
    intake.toggle(constants::INTAKE_VOLT);
    chassis.moveToPoint(-33, 23, 1000);

    //getting rings at midpoint
    chassis.turnToHeading(-90, 1000);
    chassis.moveToPose(-48, 24, -81, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(-31, 32, -104, 2000, {.forwards = false});
    chassis.turnToHeading(-80, 1000);
    chassis.moveToPoint(-46, 34, 2000);
    chassis.waitUntilDone();

    //move
    chassis.moveToPose(-27, 5, -24, 1000, {.forwards = false });
    chassis.turnToHeading(-106, 1000);
    chassis.moveToPoint(-47.4, 4, 1000, {.maxSpeed = 50});

}

void prog_skills(Intake intake, Pistons mogo, Pistons hang, Pistons doinker, Arm arm){
    //alliace stake
    chassis.setPose(0, 0, 0);
    intake.toggle(constants::INTAKE_VOLT);
    pros::delay(500);
    chassis.moveToPoint(0, 15, 1000);

    //going to mogo
    chassis.turnToHeading(-90, 1000);
    intake.toggle(constants::INTAKE_STOP);
    chassis.moveToPoint(24, 15, 1000, {.forwards = false, .maxSpeed = 60});
    chassis.waitUntil(24);
    mogo.toggle_mogo_clamp();
    
    chassis.waitUntilDone();

    //going to first ring
    chassis.turnToHeading(0, 1000);
    chassis.moveToPoint(28, 38, 1000);
    intake.toggle(constants::INTAKE_VOLT);

    //2nd ring
    chassis.turnToHeading(57, 1000);
    chassis.moveToPoint(57, 61, 2000);

    //row + last ring
    chassis.turnToHeading(180, 1000);
    chassis.moveToPoint(53.5, 0, 3500, {.maxSpeed = 40});
    pros::delay(1000);
    chassis.moveToPoint(56, 25, 1000, {.forwards = false});
    chassis.turnToHeading(141, 1000);
    chassis.moveToPoint(64, 14, 1000);
    chassis.waitUntilDone();

    //corner
    chassis.moveToPoint(58, 24, 1000, {.forwards = false});
    chassis.turnToHeading(-29, 1000);
    chassis.moveToPoint(68, 0, 1000, {.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();
    mogo.toggle_mogo_clamp();

    //going to other
    intake.toggle(constants::INTAKE_STOP);
    intake.toggle(-constants::INTAKE_VOLT);
    intake.toggle(constants::INTAKE_STOP);
    chassis.moveToPoint(62, 5, 1000);
    chassis.turnToHeading(90, 1000);
    chassis.moveToPoint(-10, 7, 5000, {.forwards = false, .maxSpeed = 60});
    chassis.waitUntilDone();
    mogo.toggle_mogo_clamp();


    //intake stop
    intake.toggle(constants::INTAKE_STOP);

}
void straight() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 15, 1000);
    }

void alliance_only(Intake intake, Pistons mogo, Pistons hang, Pistons doinker, Arm arm){
    chassis.setPose(0, 0, 0);

    chassis.moveToPoint(0, -30, 1000, {.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();
    mogo.toggle_mogo_clamp();
    chassis.turnToHeading(-90, 1000);
    chassis.moveToPoint(-20, -33, 1000);
    intake.toggle(constants::INTAKE_VOLT);
    chassis.moveToPoint(-16, -32, 1000, {.forwards = false});
    intake.toggle(constants::INTAKE_STOP);
    chassis.turnToHeading(-180, 1000);
    chassis.waitUntilDone();
    intake.toggle(constants::INTAKE_VOLT);
    chassis.moveToPoint(-14, -43, 1000, {.maxSpeed = 50});
    chassis.moveToPose(-28, -30, -223, 1000, {.forwards = false});
    chassis.turnToHeading(-180, 1000);
    chassis.moveToPoint(-25, -43, 1000);
    chassis.waitUntilDone();



    // //alliance stake
    // pros::delay(4000);
    // chassis.moveToPoint(0, -17, 1000, {.forwards = false});
    // chassis.turnToHeading(110, 1000);
    // chassis.moveToPoint(-7.5, -18, 1000, {.forwards = false, .maxSpeed = 30});
    // chassis.waitUntilDone();
    // pros::delay(300);
    // intake.toggle(constants::INTAKE_VOLT);
    // pros::delay(2000);
    // chassis.moveToPoint(8, -18, 1000, {.maxSpeed = 40});
    // intake.toggle(constants::INTAKE_STOP);
}
void alliance_only_red(Intake intake, Pistons mogo, Pistons hang, Pistons doinker, Arm arm){
    chassis.setPose(0, 0, 0);

    chassis.moveToPoint(0, -30, 1000, {.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();
    mogo.toggle_mogo_clamp();
    chassis.turnToHeading(90, 1000);
    chassis.moveToPoint(20.5, -33, 1000);
    intake.toggle(constants::INTAKE_VOLT);
    chassis.moveToPoint(16, -32, 1000, {.forwards = false});
    intake.toggle(constants::INTAKE_STOP);
    chassis.turnToHeading(180, 1000);
    chassis.waitUntilDone();
    intake.toggle(constants::INTAKE_VOLT);
    chassis.moveToPoint(14, -43, 1000, {.maxSpeed = 50});
    chassis.moveToPose(28, -30, 223, 1000, {.forwards = false});
    chassis.turnToHeading(190, 1000);
    chassis.moveToPoint(23, -45, 1000);
    chassis.waitUntilDone();
}
        