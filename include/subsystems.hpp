#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

inline pros::Motor intakeFullPre(6);
inline pros::Motor intakeHalfMid(7);
inline pros::Motor intakeHalfTop(5);

inline pros::adi::Pneumatics hood('F', false);
inline pros::adi::Pneumatics matchload('H', false);
inline pros::adi::Pneumatics wing('G', false);
inline pros::adi::Pneumatics midDescore('D', false);
// inline pros::adi::DigitalIn limit_switch('A');