#include "main.h"

bool hoodLock = false;



void intakeone(int intakePower) {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(0);
    intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
// wing.set_value(false);

// chickenstars = false;
}

void intakeall(int intakePower) {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(-intakePower);
    intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        // wing.set_value(false);
        // if(intakePower > 1) {
        //     chickenstars = false;
        // } else if (intakePower < 0) {
        //     chickenstars = true;
        // }

}


void intakemid(int intakePower) {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(intakePower - 2000);
        intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
wing.set_value(true);
// chickenstars = true;

}

void intakebottom(int intakePower) {
    intakeFullPre.move_voltage(-intakePower); 
    intakeHalfMid.move_voltage(0);
    intakeHalfTop.move_voltage(0); 
    intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
// wing.set_value(false);
// chickenstars = false;

}

void hoodToggle() {
    hoodLock = !hoodLock;
    hood.toggle();
}

