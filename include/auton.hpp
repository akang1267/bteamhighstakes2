#pragma once
#include "Pneumatics.hpp"
#include "Robot.hpp"
#include "lemlib/chassis/chassis.hpp"

extern lemlib::Chassis chassis;

void blue_solo_awp(Intake intake, Pistons mogo, Pistons hang, Pistons doinker, Arm arm);
void red_solo_awp(Intake intake, Pistons mogo, Pistons hang, Pistons doinker,Arm arm);
void red_rings_side(Intake intake, Pistons mogo, Pistons hang, Pistons doinker,Arm arm);
void blue_rings_side(Intake intake, Pistons mogo, Pistons hang, Pistons doinker, Arm arm);
void prog_skills(Intake intake, Pistons mogo, Pistons hang, Pistons doinker, Arm arm);
void tuning_pid();
void straight();
void alliance_only(Intake intake, Pistons mogo, Pistons hang, Pistons doinker, Arm arm);
void alliance_only_red(Intake intake, Pistons mogo, Pistons hang, Pistons doinker, Arm arm);