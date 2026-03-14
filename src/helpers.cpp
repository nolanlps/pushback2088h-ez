#include "main.h"


void intakeall(int intakePower) {
    intakeFullPre.move_voltage(intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(intakePower);
}

void intakemid(int intakePower) {
    intakeFullPre.move_voltage(intakePower);
    intakeHalfMid.move_voltage(intakePower);
    intakeHalfTop.move_voltage(-intakePower);
}