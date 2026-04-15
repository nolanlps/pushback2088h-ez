#include "main.h"

bool hoodLock = false;

void intakeone(int intakePower) {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(0);
    intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            midDescore.set_value(false);
}

void intakeall(int intakePower) {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(-intakePower);
    intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            midDescore.set_value(false);
}

void intakemid(int intakePower) {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(intakePower);
        intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        midDescore.set_value(true);
}

void intakebottom(int intakePower) {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(4000);
    intakeHalfTop.move_voltage(-4000);
    intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
                midDescore.set_value(false);
}

void hoodToggle() {
    hoodLock = !hoodLock;
    hood.toggle();
}
