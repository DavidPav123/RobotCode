#include "main.h"

//Setting up variables for functions
double wheelDiameterIN  = 3.25; //wheelDiameter is the measurement of a wheel from edge to edge in inches
double circumference = wheelDiameterIN * M_PI; //M_PI is math function that stands for PI

//Drive Functions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DriveStop(){
  left_back_motor.move_voltage(0);
  right_front_motor.move_voltage(0);
  right_back_motor.move_voltage(0);
  left_front_motor.move_voltage(0);
  center_right.move_voltage(0);
  center_left.move_voltage(0);
  left_back_motor.set_brake_mode(MOTOR_BRAKE_BRAKE);
  right_front_motor.set_brake_mode(MOTOR_BRAKE_BRAKE);
  right_back_motor.set_brake_mode(MOTOR_BRAKE_BRAKE);
  left_front_motor.set_brake_mode(MOTOR_BRAKE_BRAKE);
  center_right.set_brake_mode(MOTOR_BRAKE_BRAKE);
  center_left.set_brake_mode(MOTOR_BRAKE_BRAKE);
}

void timeDrive(int ppower, int time){
    double rvoltage = 120 * ppower;
    left_back_motor.move_voltage(rvoltage);
    right_front_motor.move_voltage(rvoltage);
    right_back_motor.move_voltage(rvoltage);
    left_front_motor.move_voltage(rvoltage);
    center_right.move_voltage(rvoltage);
    center_left.move_voltage(rvoltage);
    pros::delay(time);
    DriveStop();
}
///////////////////////////////////////////////////////////////////////////

//Mobile Goal Functions
///////////////////////////////////////////////////////////////////////////
void MobileGoalUp(){
  while(mobo_pot.get_value() < 10){
    mobile_goal.move_voltage(12000);
  }
  mobile_goal.move_voltage(0);
  mobile_goal.set_brake_mode(MOTOR_BRAKE_BRAKE);
}

void MobileGoalDown(){
  while(mobo_pot.get_value() > 10){
    mobile_goal.move_voltage(-12000);
  }
  mobile_goal.move_voltage(0);
  mobile_goal.set_brake_mode(MOTOR_BRAKE_BRAKE);
}
///////////////////////////////////////////////////////////////////////////
