#pragma once
#include "api.h"

class Pistons {
    private:
        pros::adi::Pneumatics mogo_clamp; 
        pros::adi::Pneumatics hang;
        pros::adi::Pneumatics doinker;
        bool hang_on_state = false;
        bool mogo_clamp_state = false; 

    public:
        Pistons(uint8_t port_mogo, uint8_t port_hang, uint8_t port_doinker, bool mogo_state, bool hang_state, bool doinker_state);
        bool doinker_state = false;
        
        void toggle_mogo_clamp(); 
        void toggle_hang();
        void toggle_doinker();
        bool get_state_hang();
        bool get_state_mogo_clamp();
        bool get_state_doinker();
    
};