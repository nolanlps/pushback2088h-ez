#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

inline pros::Motor intakeFullPre(-3);
inline pros::Motor intakeHalfMid(-2);
inline pros::Motor intakeHalfTop(1);

inline pros::adi::Pneumatics hood('A', false);
inline pros::adi::Pneumatics matchload('B', false);
inline pros::adi::Pneumatics wing('C', false);
inline pros::adi::Pneumatics midDescore('D', false);
// inline pros::adi::DigitalIn limit_switch('A');