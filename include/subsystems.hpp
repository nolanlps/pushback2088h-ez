#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;


inline pros::MotorGroup left_mg({12, -13, 11});
inline pros::MotorGroup right_mg({19, -17, -16});

inline pros::Motor intakeFullPre(14);
inline pros::Motor intakeHalfMid(15);
inline pros::Motor intakeHalfTop(20);

inline pros::adi::Pneumatics hood('H', false);
inline pros::adi::Pneumatics matchload('G', false);
inline pros::adi::Pneumatics wing('D', false);
inline pros::adi::Pneumatics midDescore('C', false);
// inline pros::adi::DigitalIn limit_switch('A');