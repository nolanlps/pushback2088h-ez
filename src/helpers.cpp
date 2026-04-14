#include "main.h"

bool hoodLock = false;

void intakeone(int intakePower) {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(0);
    intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void intakeall(int intakePower) {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(-intakePower);
    intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

void intakemid(int intakePower) {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(intakePower);
        intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

void intakebottom(int intakePower) {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(4000);
    intakeHalfTop.move_voltage(-4000);
    intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void hoodToggle() {
    hoodLock = !hoodLock;
    hood.toggle();
}
