#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 110;

///
// Constants
///


void default_constants() {
  // P, I, D, and Start I
//   chassis.pid_drive_constants_forward_set(20.0, 0.0, 100.0);
// chassis.pid_drive_constants_backward_set(20.0, 0.0, 100.0);
  chassis.pid_drive_constants_set(16.7, 0.0, 112.50, 0.0);         // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(11.0, 0.0, 20.0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(3.4, 0.038, 24.50, 15.0);     // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 65.0);           // Swing constants
  chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5);  // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(10_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

void driveforwards() {
  chassis.pid_drive_set(5_in, 80, false);
  chassis.pid_wait();
}

void right() {
  pros::delay(20);
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater than the slew distance + a few inches

  chassis.pid_drive_set(24_in, 70, true);
  chassis.pid_wait();

  pros::delay(1000);

  chassis.pid_drive_set(-12_in, 70);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, 70);
  chassis.pid_wait();
}
void right4ballrush() {
  // ## RIGHT 3 Block score 3 grab 3 wing ##

    pros::delay(20);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    chassis.drive_angle_set(0_deg);
    pros::delay(20);

    intakeall(12000);
    hood.toggle();

  chassis.pid_drive_set(34_in, 75, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, 90);
  chassis.pid_wait();

  matchload.toggle();
  chassis.pid_drive_set(12_in, 50, true);

  pros::delay(1000);

  chassis.pid_drive_set(-38_in, 75);
  chassis.pid_wait();

  hood.toggle();

  pros::delay(1000);

  matchload.toggle();
  hood.toggle();

  chassis.drive_brake_set(MOTOR_BRAKE_HOLD); // change to coast later or smtn
  chassis.pid_odom_set({{-25_in, 11_in}, fwd, 80}, true);
  chassis.pid_wait();
  matchload.toggle();
    
  chassis.pid_odom_set({{{-8_in, 26_in}, rev, 90},
                       {{-22_in, 26_in}, rev, 90}},
                      true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, 90);
  chassis.pid_wait();

  chassis.pid_odom_set({{{-38_in, 27_in}, rev, 90}}, true);
  chassis.pid_wait();

}

void right7ballrush() {
// ## RIGHT 7 block potentially ##

    pros::delay(20);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    chassis.drive_angle_set(0_deg);
    pros::delay(20);

    intakeone(12000);
    chassis.pid_odom_set({{{8_in, 28_in}, fwd, 90}}, true);
    chassis.pid_wait();
    matchload.toggle();

    chassis.pid_odom_set({{{32_in, 0_in}, rev, 90}}, true);
    chassis.pid_wait();

    chassis.pid_turn_set(180_deg, 90);
    chassis.pid_wait();

    chassis.pid_odom_set({{{32_in, -16_in}, fwd, 80}});
    chassis.pid_wait();
    pros::delay(100);

    chassis.pid_odom_set({{{33.5_in, 22_in}, rev, 90}});
    chassis.pid_wait();
    hoodToggle();
    intakeall(12000);
    pros::delay(1650);
    intakeone(12000);

  chassis.pid_odom_set({{{23.5_in, 13_in}, fwd, 90}});
  chassis.pid_wait();

  chassis.pid_turn_set(180_deg, 90);
 chassis.pid_wait_quick_chain();

  chassis.pid_odom_set({{{23.5_in, 22_in}, rev, 80}, {{26_in, 32_in}, rev, 90}}, true);
  chassis.pid_wait();

  chassis.pid_wait();
    chassis.pid_turn_set(120_deg, 40);

  // chassis.pid_turn_set(120_deg, 40);

 

    // chassis.pid_swing_set(LEFT_SWING, 270, 100, 0);
    // chassis.pid_wait_quick_chain();
    // chassis.pid_drive_set(4, 80);
    // chassis.pid_wait_quick_chain();
    // chassis.pid_turn_set(180, 80);
    // chassis.pid_wait();
    // chassis.pid_drive_set(-10, 80);

}

void right4long3mid() {

  pros::delay(20);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    chassis.drive_angle_set(0_deg);
    pros::delay(20);

    intakebottom(12000);
    chassis.pid_odom_set({{{7_in, 25_in}, fwd, 80}}, true);
    pros::delay(300);
    chassis.pid_wait();

    chassis.pid_odom_set({{{-7.5_in, 43.5_in, 315_deg}, fwd, 100}}, true);//meowmoewoemowmewo
    chassis.pid_wait(); 

    intakeall(-10000); //wow lyla ur so kawaii
    pros::delay(1200);

    chassis.pid_odom_set({{{32_in, 4_in}, rev, 70}}, true);
    chassis.pid_wait();
    matchload.toggle();
    intakeone(12000);

    chassis.pid_turn_set(180_deg, 90);
    chassis.pid_wait();

    chassis.pid_drive_set(17_in, 75);
    // chassis.pid_odom_set({{{32_in, -16_in}, fwd, 80}});
    chassis.pid_wait_until(13.7_in);
    pros::delay(250);

    chassis.pid_odom_set({{{32.5_in, 38_in, 180_deg}, rev, 100}});
    pros::delay(650);
    hoodToggle();
    intakeall(12000);
    pros::delay(1000);
    hoodToggle();
    intakeone(12000);

  chassis.pid_odom_set({{{22_in, 18_in}, fwd, 100}});
  chassis.pid_wait();

  chassis.pid_turn_set(180_deg, 90);
 chassis.pid_wait();

  chassis.pid_odom_set({{{21_in, 22_in}, rev, 100}, {{25_in, 39_in}, rev, 90}}, true);

  chassis.pid_wait();
    chassis.pid_turn_set(120_deg, 40);
  // hoodToggle();
  // intakeall(12000);


//lyla is the best and smartest person in the world and i love her so much and she is so cute and amazing and wow i wish i could be like her and be as good at coding as her because she is just so amazing and talented and wow i just love her so much
  // pros::delay(20);
  // chassis.odom_xyt_set(0_in, 0_in, 0_deg);
  // chassis.drive_angle_set(0_deg);
  // pros::delay(20);

  // intakeall(12000);
  // hood.toggle();

  // chassis.pid_drive_set(34_in, 75, true);
  // chassis.pid_wait();

  // chassis.pid_turn_set(90_deg, 90);
  // chassis.pid_wait();

  // matchload.toggle();
  // chassis.pid_drive_set(12_in, 50, true);

  // pros::delay(1000);

  // chassis.pid_drive_set(-38_in, 75);
  // chassis.pid_wait();

  // hood.toggle();
  // matchload.toggle();
  // hood.toggle();

  // intakeall(10000);
  // chassis.pid_odom_set({{-25_in, 11_in}, fwd, 80}, true);
  // chassis.pid_wait();
  
  // chassis.pid_odom_set({{-36.5_in, 0.5_in}, fwd, 80}, true);
  // chassis.pid_wait();
  // intakeall(-12000);
  // pros::delay(2000);
  // intakeall(12000);

  // chassis.pid_odom_set({{{-8_in, 26_in}, rev, 90},
  //                      {{-22_in, 26_in}, rev, 90}},
  //                     true);
  // chassis.pid_wait();

  // chassis.pid_turn_set(90_deg, 90);
  // chassis.pid_wait();

  // chassis.pid_odom_set({{{-38_in, 28_in}, rev, 90}}, true);
  // chassis.pid_wait();

}

void left4ballrush() {

  pros::delay(20);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    chassis.drive_angle_set(0_deg);
    pros::delay(20);

    intakeall(12000);
    hood.toggle();

  chassis.pid_drive_set(34_in, 75, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, 90);
  chassis.pid_wait();

  matchload.toggle();
  chassis.pid_drive_set(-12_in, 50, true);

  pros::delay(1000);

  chassis.pid_drive_set(-38_in, 75);
  chassis.pid_wait();

  hood.toggle();

  pros::delay(1000);

  matchload.toggle();
  hood.toggle();

  chassis.drive_brake_set(MOTOR_BRAKE_HOLD); // change to coast later or smtn
  chassis.pid_odom_set({{25_in, 11_in}, fwd, 80}, true);
  chassis.pid_wait();
  matchload.toggle();
    
  chassis.pid_odom_set({{{8_in, 26_in}, rev, 90},
                       {{22_in, 26_in}, rev, 90}},
                      true);
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, 90);
  chassis.pid_wait();

  chassis.pid_odom_set({{{38_in, 27_in}, rev, 90}}, true);
  chassis.pid_wait();

}

void left7ballrush() {

  pros::delay(20);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    chassis.drive_angle_set(0_deg);
    pros::delay(20);
    hood.toggle();

    intakeall(12000);
    chassis.pid_odom_set({{{-7_in, 25_in}, fwd, 90}}, true);
    chassis.pid_wait();
    matchload.toggle();

    chassis.pid_odom_set({{{-34.5_in, 0_in}, rev, 90}}, true);
    chassis.pid_wait();
    
    chassis.pid_turn_set(180_deg, 90);
    chassis.pid_wait();

    chassis.pid_odom_set({{{-34_in, -16_in}, fwd, 80}});
    chassis.pid_wait();
    pros::delay(300);

    chassis.pid_odom_set({{{-34_in, 24_in}, rev, 90}});
    chassis.pid_wait();
    matchload.toggle();
    hood.toggle();
        intakeall(12000);
    pros::delay(1500);
    intakeall(0);

    chassis.pid_odom_set({{{-41.5_in, 18_in}, fwd, 90}});
  chassis.pid_wait();

  chassis.pid_turn_set(180_deg, 90);
 chassis.pid_wait_quick_chain();

  chassis.pid_odom_set({{{-41.5_in, 22_in}, rev, 80}, {{-43_in, 36_in}, rev, 90}}, true);
  chassis.pid_wait();

  chassis.pid_turn_set(120_deg, 40);

    // chassis.pid_swing_set(LEFT_SWING, 270, 100, 0);
    // chassis.pid_wait_quick_chain();
    // chassis.pid_drive_set(4, 80);
    // chassis.pid_wait_quick_chain();
    // chassis.pid_turn_set(180, 80);
    // chassis.pid_wait();
    // chassis.pid_drive_set(-24, 80);

}

void left4long3mid() {

  pros::delay(20);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    chassis.drive_angle_set(0_deg);
    pros::delay(20);

  // hoodToggle();
    intakeone(12000);
    chassis.pid_odom_set({{{-5.5_in, 28_in}, fwd, 100}}, true);
    chassis.pid_wait_until(20_in);
    matchload.toggle();
    chassis.pid_wait();

    chassis.pid_odom_set({{{7.7_in, 41.5_in}, rev, 90}}, true);//meowmoewoemowmewo
    chassis.pid_wait(); 
      hoodToggle();
  
    intakemid(12000); //wow lyla ur so kawaii
    pros::delay(1000);
      hoodToggle();
    intakeall(-12000);
    wing.set_value(false);

    chassis.pid_odom_set({{{-34.5_in, 0_in}, fwd, 90}}, true);
    intakeone(12000);
    chassis.pid_wait();

    chassis.pid_turn_set(180_deg, 80);
    chassis.pid_wait();

  // chassis.pid_odom_set({{{-35.5_in, -8_in}, fwd, 70}});
  //   chassis.pid_wait();
  chassis.pid_drive_set(14.5_in, 120);
  // chassis.pid_wait_until(11.5_in);
  // chassis.pid_drive_set(2_in, 80);
  chassis.pid_wait();
  pros::delay(40);

    chassis.pid_odom_set({{{-34_in, 26_in}, rev, 70}});
    pros::delay(650);
    hoodToggle();
    intakeall(12000);
    pros::delay(1150);
    hoodToggle();
    intakeone(12000);
    matchload.toggle();

  chassis.pid_odom_set({{{-47.5_in, 12_in}, fwd, 100}});
  chassis.pid_wait();
    wing.set_value(false);

  chassis.pid_turn_set(180_deg, 110);
 chassis.pid_wait();
 
  chassis.pid_odom_set({{{-46.5_in, 22_in}, rev, 100}, {{-42_in, 34_in}, rev, 70}}, true);
  chassis.pid_wait();

  chassis.pid_turn_set(120_deg, 60);

  // pros::delay(20);
  // chassis.odom_xyt_set(0_in, 0_in, 0_deg);
  // chassis.drive_angle_set(0_deg);
  // pros::delay(20);

  // intakeall(12000);
  // hood.toggle();

  // chassis.pid_drive_set(34_in, 75, true);
  // chassis.pid_wait();

  // chassis.pid_turn_set(-90_deg, 90);
  // chassis.pid_wait();

  // matchload.toggle();
  // chassis.pid_drive_set(12_in, 50, true);

  // pros::delay(1000);

  // chassis.pid_drive_set(-38_in, 75);
  // chassis.pid_wait();

  // hood.toggle();
  // matchload.toggle();
  // hood.toggle();

  // intakeall(10000);
  // chassis.pid_odom_set({{25_in, 11_in}, fwd, 80}, true);
  // chassis.pid_wait();
  
  // chassis.pid_odom_set({{36.5_in, 0.5_in}, fwd, 80}, true);
  // chassis.pid_wait();
  // intakeall(-12000);
  // pros::delay(2000);
  // intakeall(12000);

  // chassis.pid_odom_set({{{8_in, 26_in}, rev, 90},
  //                      {{22_in, 26_in}, rev, 90}},
  //                     true);
  // chassis.pid_wait();

  // chassis.pid_turn_set(-90_deg, 90);
  // chassis.pid_wait();

  // chassis.pid_odom_set({{{38_in, 28_in}, rev, 90}}, true);
  // chassis.pid_wait();
  
}

void counterSawp() {
    chassis.drive_brake_set(MOTOR_BRAKE_HOLD);

  pros::delay(100);
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);
  chassis.drive_angle_set(0_deg);
  pros::delay(20);

  // hoodToggle();
  matchload.toggle();
  intakeone(12000);

    chassis.drive_brake_set(MOTOR_BRAKE_HOLD);
 chassis.pid_odom_set({{0_in, -34_in}, rev, 90}, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(10.2_in, 100);
  chassis.pid_wait_quick_chain();
  pros::delay(400);
  // chassis.pid_wait_until(11_in);
  // chassis.pid_drive_set(2_in, 80);s
  // chassis.pid_wait();
  // pros::delay(120); // if we need time to intake from matchloader later

  chassis.pid_odom_set({{22_in, -35.5_in}, rev, 100});
  pros::delay(600);
  hoodToggle();
    matchload.toggle();
  intakeall(12000);
  pros::delay(900); // score into goal
  intakeone(12000);



  // chassis.pid_swing_set(ez::LEFT_SWING, 100_deg, 120, 0);
  // chassis.pid_wait_quick_chain();

  chassis.pid_odom_set({{{19_in, -10_in}, fwd, 110}, {{20_in, 32_in}, fwd, 110}, {{-10_in, 61.75_in}, fwd, 90}}, 
                      true); // yo llya dont run overheated the sawp is working better thatn yesterday rn 

    pros::delay(700);
    hoodToggle();
    pros::delay(1700);
    matchload.toggle();
    chassis.pid_wait();


  chassis.pid_turn_set(-92_deg, 110);
  chassis.pid_wait();

  // chassis.pid_odom_set({{{32_in, 63.5_in}, rev, 80}}, true);
  chassis.pid_drive_set(-15, 80);
  pros::delay(600);
  hoodToggle();
  intakeall(12000);
   pros::delay(1300);
  chassis.odom_xyt_set(0_in, 0_in, 0_deg); // reset
  chassis.drive_angle_set(0_deg);
  pros::delay(20);
  intakeone(12000);

  // chassis.pid_turn_set(-2_deg, 120);

  // chassis.pid_wait_quick_chain();

  // chassis.pid_odom_set({{0_in, 34_in}, fwd, 120});
  // chassis.pid_drive_set(30, 80, true);
  chassis.pid_odom_set({{0, 28}, fwd, 80});

  // chassis.pid_wait_quick_chain();
  // chassis.pid_turn_set(-10, 100);
  chassis.pid_wait_quick_chain();
      hoodToggle();
  chassis.pid_drive_set(4, 30);
  chassis.pid_wait_quick_chain();
  pros::delay(380);
  intakeone(12000);
  chassis.pid_drive_set(-6_in, 120, false);
  chassis.pid_wait();
  chassis.pid_odom_set({{-41.25, -19.75}, rev, 100});
  chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-2_in, 100, false);
  // matchload.toggle();
  // chassis.pid_wait_quick_chain(); 
  // hoodToggle();
  intakeall(12000);
  pros::delay(10);
  // intakeall(-12000);
  // pros::delay(200);
  intakemid(5000);
  pros::delay(2000);
  intakeall(0);

  pros::delay(100000); // ++++++++++++++++++++++++++++++++++++++++++++++++

  pros::delay(100);
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);
  chassis.drive_angle_set(0_deg);
  pros::delay(20);

  // hoodToggle();
  matchload.toggle();
  intakeone(12000);

 chassis.pid_odom_set({{0_in, -34.2_in}, rev, 100});
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, 120);
  chassis.pid_wait();

  chassis.pid_drive_set(13_in, 120);
  // chassis.pid_wait_until(11.5_in);
  // chassis.pid_drive_set(2_in, 80);
  // chassis.pid_wait_quick_chain();
  //   chassis.pid_drive_set(1.5_in, 80, false);
  chassis.pid_wait();
  pros::delay(20); // if we need time to intake from matchloader later

  chassis.pid_odom_set({{22_in, -36.5_in}, rev, 100});
  pros::delay(650);
  hoodToggle();
  intakeall(12000);
  pros::delay(1100); // score into goal
  matchload.toggle();  
  intakeone(12000);
  hoodToggle();

  // chassis.pid_swing_set(ez::LEFT_SWING, 100_deg, 120, 0);
  // chassis.pid_wait_quick_chain();

  chassis.pid_odom_set({{{18_in, -10_in}, fwd, 110}, {{19_in, 32_in}, fwd, 110}, {{-12_in, 63_in}, fwd, 90}}, 
                      true);
  chassis.pid_wait();
  matchload.toggle();

  chassis.pid_turn_set(-90_deg, 110);
  chassis.pid_wait();

  chassis.pid_odom_set({{{26_in, 63_in}, rev, 110}}, true);
  pros::delay(400);
  hoodToggle();
  intakeall(12000);
  pros::delay(1600);

  pros::delay(100);
  chassis.odom_xy_set(0_in, 0_in);
  pros::delay(20);

  // chassis.pid_odom_set({{0_in, 34_in}, fwd, 120});
  chassis.pid_drive_set(33.5_in, 110, false);
  chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(1_in, 80, false);
  pros::delay(100);
  hoodToggle();
  intakeone(12000);

  // pros::delay(20);
  intakeone(12000);
  chassis.pid_drive_set(-6_in, 120, false);
  chassis.pid_wait();
  chassis.pid_odom_set({{21_in, -43_in}, rev, 100});
  chassis.pid_wait_quick_chain();
      chassis.pid_turn_set(-45_deg, 120);
    chassis.pid_wait();

  // chassis.pid_drive_set(-2_in, 100, false);
  matchload.toggle();
  chassis.pid_wait(); 
  // hoodToggle();
  intakeall(12000);
  pros::delay(10);
  // intakeall(-12000);
  // pros::delay(200);
  intakemid(12000);

  // THEORETICAL

   pros::delay(100000);

   pros::delay(100);
  chassis.odom_xy_set(0_in, 0_in);
  pros::delay(20);

  chassis.pid_drive_set(34.5_in, 110, false);
  chassis.pid_wait();
  intakeone(12000);
  chassis.pid_drive_set(-6_in, 120, false);
  chassis.pid_wait();
  chassis.pid_odom_set({{21_in, -38_in}, rev, 100});
  chassis.pid_wait();
  chassis.pid_turn_set(-45_deg, 120);
  chassis.pid_drive_set(-2_in, 100, false);
  matchload.toggle();
  chassis.pid_wait_quick_chain();
  hoodToggle();
  intakemid(12000);





  pros::delay(100000);

  chassis.pid_drive_set(22_in, 120);
  chassis.pid_wait_until(20_in);

  // chassis.pid_odom_set({{20_in, 61_in}, rev, 120}, true);
  chassis.pid_drive_set(-48_in, 120);
  chassis.pid_wait_until(-40_in);
  hoodToggle();
  pros::delay(1000);

  hoodToggle();

  chassis.pid_odom_set({{{0_in, 61_in}, fwd, 120}, {{30_in, 20_in}, rev, 120}}, true);
  

  // +++ 

  // chassis.pid_odom_set({{-14_in, 61_in}, rev, 110}, true);
  // chassis.pid_drive_set(30_in, 120);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(5_in, 70);
  // pros::delay(50);


    // intakeall(0);
    // chassis.pid_drive_set(-10_in, 120);
    // chassis.pid_wait();
    // chassis.pid_odom_set({{-6_in, 63_in}, rev, 120}, true);
    // pros::delay(100);
    // matchload.toggle();
    // intakemid(12000);


  // chassis.pid_odom_set({{25_in, -11_in}, fwd, 90}, true);
  // // chassis.pid_wait();
  // // matchload.toggle();

  // chassis.pid_odom_set({{25_in, 35_in}, fwd, 100}, true);

  
  // chassis.pid_odom_set({{{-30, 0}, rev, 0}});
  // hood.retract();
  // intakeall(127);
  // matchloader.toggle();
  // chassis.pid_wait();

  // chassis.pid_turn_set(-90);
  // chassis.pid_wait();

  // chassis.pid_drive_set(5, 80);
  // chassis.pid_wait();

  // chassis.pid_odom_set({{{-30, 27}, rev, -90}});
  // chassis.pid_wait();
  // hood.extend();
  // pros::delay(600);
  // hood.retract();

  // chassis.pid_swing_set(R_SWING, 45, 90, 30);
  // chassis.pid_wait();
  
  // chassis.pid_turn_set(-10, 80);
  // chassis.pid_wait();

  // chassis.pid_odom_set({{{-8, 30}, fwd, -15}});
  // chassis.pid_wait();
}

void skills() {
  pros::delay(100);
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);
  chassis.drive_angle_set(0_deg);
  pros::delay(20);

  intakeone(12000);

  chassis.pid_odom_set({{{0_in, 34_in}, fwd, 75}}, true);
  matchload.toggle();
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, 90);
  chassis.pid_wait();

    intakeone(12000);

  chassis.pid_drive_set(13_in, 80, true);
  chassis.pid_wait();
  pros::delay(1500);

  chassis.pid_odom_set({{{0_in, 34_in}, rev, 75}}, true);
  chassis.pid_wait();

chassis.pid_turn_set(-180_deg, 75);
chassis.pid_wait();

chassis.pid_odom_set({{{0_in, 64_in}, rev, 70}}, true);
chassis.pid_wait();
// chassis.pid_drive_set(-2_in, 80);
// chassis.pid_wait();

  pros::delay(100);
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);
  chassis.drive_angle_set(0_deg);
  pros::delay(20);

// chassis.pid_turn_set(-90_deg, 90);
// chassis.pid_wait();

chassis.pid_odom_set({{{-96_in, -2_in}, fwd, 75}}, true);
chassis.pid_wait();

chassis.pid_turn_set(0_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(-10_in, 90);
chassis.pid_wait();

pros::delay(100);
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);
  pros::delay(20);

chassis.pid_odom_set({{{0_in, 14.5_in}, fwd, 75}}, true);
chassis.pid_wait();

chassis.pid_turn_set(-90_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(-16_in, 110, true);
chassis.pid_wait();

hoodToggle();
intakeall(12000);
pros::delay(2500);

  pros::delay(100);
  chassis.odom_xy_set(0_in, 0_in);
  pros::delay(20);


  chassis.pid_odom_set({{{-35.2_in, 0_in}, fwd, 70}}, true);
  chassis.pid_wait();
intakeone(12000);
hoodToggle();
    pros::delay(1500);

chassis.pid_drive_set(-36_in, 80, true);
chassis.pid_wait();

hoodToggle();
intakeall(12000);
pros::delay(2500);

  pros::delay(100);
  chassis.odom_xy_set(0_in, 0_in);
  pros::delay(20);

//   chassis.pid_drive_set(2_in, 60, false);
// chassis.pid_wait();
  matchload.toggle();

  chassis.pid_drive_set(10_in, 80, true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, 90);
  chassis.pid_wait();
  
  chassis.pid_odom_set({{{10_in, 20_in}, fwd, 75}}, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, 90);
  chassis.pid_wait();

  chassis.pid_odom_set({{{102_in, 15_in}, fwd, 75}}, true);
  chassis.pid_wait();

  chassis.pid_turn_set(10_deg, 90);
  chassis.pid_wait();

  chassis.pid_drive_set(60_in, 120);
  chassis.pid_wait();

//   // hoodToggle();
//   matchload.toggle();
//   intakeone(12000);

//  chassis.pid_odom_set({{0_in, -35_in}, rev, 100});
//   chassis.pid_wait();

//   chassis.pid_turn_set(-90_deg, 120);
//   chassis.pid_wait();

//   chassis.pid_drive_set(13_in, 120);
//   // chassis.pid_wait_until(11.5_in);
//   // chassis.pid_drive_set(2_in, 80);
//   chassis.pid_wait();
//   pros::delay(500); // if we need time to intake from matchloader later
//   chassis.pid_drive_set(1_in, 80);
//   chassis.pid_wait();

//   chassis.pid_odom_set({{22_in, -35.5_in}, rev, 90});
//   pros::delay(650);
//   hoodToggle();
//   intakeall(12000);
//   pros::delay(2000); // score into goal
//   hoodToggle();
//   intakeone(12000);
//   matchload.toggle();

//   // chassis.pid_swing_set(ez::LEFT_SWING, 100_deg, 120, 0);
//   // chassis.pid_wait_quick_chain();

//   chassis.pid_odom_set({{{18_in, -10_in}, fwd, 80}, {{19_in, 32_in}, fwd, 80}, {{-12_in, 63.5_in}, fwd, 80}}, 
//                       true);
//   chassis.pid_wait();
//   matchload.toggle();

//   chassis.pid_turn_set(-90_deg, 100);
//   chassis.pid_wait();

//   chassis.pid_odom_set({{{32_in, 62.5_in}, rev, 110}}, true);
//   pros::delay(400);
//   hoodToggle();
//   intakeall(12000);
//   pros::delay(4000);
//   intakeall(-12000);
//   pros::delay(1000);
//   hoodToggle();
//   intakeone(12000);

//   pros::delay(100);
//   chassis.odom_xyt_set(0_in, 0_in, 0_deg);
//   chassis.drive_angle_set(0_deg);
//   pros::delay(20);

//   // chassis.pid_odom_set({{0_in, 34_in}, fwd, 120});
//   chassis.pid_drive_set(35_in, 90, false);
//   chassis.pid_wait();
//   chassis.pid_drive_set(2_in, 80);
//   chassis.pid_wait();
//   pros::delay(500);
//   chassis.pid_drive_set(2_in, 80);
//   chassis.pid_wait();
//   chassis.pid_drive_set(-6_in, 120, false);
//   chassis.pid_wait();
//   chassis.pid_odom_set({{-40.5_in, -20_in}, rev, 100});
//   chassis.pid_wait();
//   chassis.pid_turn_set(45_deg, 120);
//   // chassis.pid_drive_set(-2_in, 100, false);
//   matchload.toggle();
//   chassis.pid_wait_quick_chain(); 
//   hoodToggle();
//   intakemid(12000);
//   pros::delay(2000);
//   chassis.pid_odom_set({{-52_in, -8_in}, fwd, 80});
//   chassis.pid_wait();
//   chassis.pid_turn_set(0_deg, 120);
//   chassis.pid_wait();
//   chassis.pid_odom_set({{-52_in, 35_in}, fwd, 100});
//   chassis.pid_wait();
//   chassis.pid_turn_set(0_deg, 120);
//   chassis.pid_wait();
//   pros::delay(2000);
//   chassis.pid_drive_set(40_in, 120);
//   chassis.pid_wait();
//   chassis.pid_drive_set(40_in, 120);
//   chassis.pid_wait();
//   intakemid(12000);
}

///
// Turn Example
///
void turn_example() {
  // The first parameter is the target in degrees
  // The second parameter is max speed the robot will drive at

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(24_in, 30, true);
  chassis.pid_wait_until(6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // When the robot gets to -6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(-24_in, 30, true);
  chassis.pid_wait_until(-6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is the target in degrees
  // The third parameter is the speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();
}

///
// Motion Chaining
///
void motion_chaining() {
  // Motion chaining is where motions all try to blend together instead of individual movements.
  // This works by exiting while the robot is still moving a little bit.
  // To use this, replace pid_wait with pid_wait_quick_chain.
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // Your final motion should still be a normal pid_wait
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backward
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered) {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If the robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, the robot will drive forward and turn 90 degrees.
// If interfered, the robot will drive forward and then attempt to drive backward.
void interfered_example() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Odom Drive PID
///
void odom_drive_example() {
  // This works the same as pid_drive_set, but it uses odom instead!
  // You can replace pid_drive_set with pid_odom_set and your robot will
  // have better error correction.

  chassis.pid_odom_set(24_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
}

///
// Odom Pure Pursuit
///
void odom_pure_pursuit_example() {
  // Drive to 0, 30 and pass through 6, 10 and 0, 20 on the way, with slew
  chassis.pid_odom_set({{{6_in, 10_in}, fwd, DRIVE_SPEED},
                        {{0_in, 20_in}, fwd, DRIVE_SPEED},
                        {{0_in, 30_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait();

  // Drive to 0, 0 backwards
  chassis.pid_odom_set({{0_in, 0_in}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Odom Pure Pursuit Wait Until
///
void odom_pure_pursuit_wait_until_example() {
  chassis.pid_odom_set({{{0_in, 24_in}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait_until_index(1);  // Waits until the robot passes 12, 24
  // Intake.move(127);  // Set your intake to start moving once it passes through the second point in the index
  chassis.pid_wait();
  // Intake.move(0);  // Turn the intake off
}

///
// Odom Boomerang
///
void odom_boomerang_example() {
  chassis.pid_odom_set({{0_in, 24_in, 45_deg}, fwd, DRIVE_SPEED},
                       true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Odom Boomerang Injected Pure Pursuit
///
void odom_boomerang_injected_pure_pursuit_example() {
  chassis.pid_odom_set({{{0_in, 24_in, 45_deg}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Calculate the offsets of your tracking wheels
///
void measure_offsets() {
  // Number of times to test
  int iterations = 10;

  // Our final offsets
  double l_offset = 0.0, r_offset = 0.0, b_offset = 0.0, f_offset = 0.0;

  // Reset all trackers if they exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->reset();
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->reset();
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->reset();
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->reset();
  
  for (int i = 0; i < iterations; i++) {
    // Reset pid targets and get ready for running an auton
    chassis.pid_targets_reset();
    chassis.drive_imu_reset();
    chassis.drive_sensor_reset();
    chassis.drive_brake_set(MOTOR_BRAKE_HOLD);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    double imu_start = chassis.odom_theta_get();
    double target = i % 2 == 0 ? 90 : 270;  // Switch the turn target every run from 270 to 90

    // Turn to target at half power
    chassis.pid_turn_set(target, 63, ez::raw);
    chassis.pid_wait();
    pros::delay(250);

    // Calculate delta in angle
    double t_delta = util::to_rad(fabs(util::wrap_angle(chassis.odom_theta_get() - imu_start)));

    // Calculate delta in sensor values that exist
    double l_delta = chassis.odom_tracker_left != nullptr ? chassis.odom_tracker_left->get() : 0.0;
    double r_delta = chassis.odom_tracker_right != nullptr ? chassis.odom_tracker_right->get() : 0.0;
    double b_delta = chassis.odom_tracker_back != nullptr ? chassis.odom_tracker_back->get() : 0.0;
    double f_delta = chassis.odom_tracker_front != nullptr ? chassis.odom_tracker_front->get() : 0.0;

    // Calculate the radius that the robot traveled
    l_offset += l_delta / t_delta;
    r_offset += r_delta / t_delta;
    b_offset += b_delta / t_delta;
    f_offset += f_delta / t_delta;
  }

  // Average all offsets
  l_offset /= iterations;
  r_offset /= iterations;
  b_offset /= iterations;
  f_offset /= iterations;

  // Set new offsets to trackers that exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->distance_to_center_set(l_offset);
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->distance_to_center_set(r_offset);
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->distance_to_center_set(b_offset);
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->distance_to_center_set(f_offset);
}

// . . .
// Make your own autonomous functions here!
// . . .