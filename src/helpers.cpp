#include "main.h"

bool hoodLock = false;



void intakeone(int intakePower) {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(0);
    intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    midDescore.set_value(false);
// wing.set_value(false);

// chickenstars = false;
}

void intakeall(int intakePower) {
    // yo comment this out if no wokr
    if(intakePower < 0) {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(0);
    } else {
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(-intakePower);
    }
        // ey bruh if ts above no work uncomment this
    // intakeFullPre.move_voltage(-intakePower); 
    // intakeHalfMid.move_voltage(intakePower);
    // intakeHalfTop.move_voltage(-intakePower);
    intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    midDescore.set_value(false);
        // wing.set_value(false);
        // if(intakePower > 1) {
        //     chickenstars = false;
        // } else if (intakePower < 0) {
        //     chickenstars = true;
        // }

}


void intakemid(int intakePower) {
midDescore.set_value(true);
    intakeFullPre.move_voltage(-intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(intakePower);
        intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
         pros::delay(200);

// chickenstars = true;

}

void intakebottom(int intakePower) {
    intakeFullPre.move_voltage(intakePower); 
    intakeHalfMid.move_voltage(-intakePower);
    intakeHalfTop.move_voltage(0); 
    intakeHalfTop.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
// wing.set_value(false);
midDescore.set_value(false);
// chickenstars = false;

}

void hoodToggle() {
    hoodLock = !hoodLock;
    hood.toggle();
}

void forwards(int voltage){
    left_mg.move_voltage(voltage);
    right_mg.move_voltage(voltage);
}

