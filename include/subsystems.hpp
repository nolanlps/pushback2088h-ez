#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;


inline pros::Motor intakeFullPre(14);
inline pros::Motor intakeHalfMid(15);
inline pros::Motor intakeHalfTop(20);

inline pros::adi::Pneumatics hood('F', false);
inline pros::adi::Pneumatics matchload('H', false);
inline pros::adi::Pneumatics wing('G', false);
inline pros::adi::Pneumatics midDescore('D', false);
// inline pros::adi::DigitalIn limit_switch('A');