#include "Pneumatics.hpp"


// Constructor 
Pistons::Pistons(uint8_t port_mogo, uint8_t port_hang, uint8_t port_doinker, bool mogo_state, bool hang_state, bool doinker_state): 
    mogo_clamp {port_mogo, false},
    hang {port_hang, false},
    doinker {port_doinker, false}
    {};


void Pistons::toggle_mogo_clamp() {
    mogo_clamp_state = !mogo_clamp_state; // switches wing state
    mogo_clamp.set_value(mogo_clamp_state);
    mogo_clamp.set_value(mogo_clamp_state);    
}

// returns wing state
bool Pistons::get_state_mogo_clamp() {
    return mogo_clamp_state; 
}

void Pistons::toggle_hang(){
    hang_on_state = !hang_on_state; // switches wing state
    hang.set_value(hang_on_state);
    hang.set_value(hang_on_state);
}

bool Pistons::get_state_hang(){
    return hang_on_state;
}

void Pistons::toggle_doinker(){
    doinker_state = !doinker_state;
    doinker.set_value(doinker_state);
    doinker.set_value(doinker_state);
}

bool Pistons::get_state_doinker() {
    return doinker_state;
}
