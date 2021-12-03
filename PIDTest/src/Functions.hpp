#include "main.h"

//Setting up variables for functions
double wheelDiameterIN  = 3.25; //wheelDiameter is the measurement of a wheel from edge to edge in inches
double circumference = wheelDiameterIN * M_PI; //M_PI is math function that stands for PI

//Drive Functionsa
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

void timeDrive(int rvoltage, int time){
    left_back_motor.move_voltage(rvoltage);
    right_front_motor.move_voltage(rvoltage);
    right_back_motor.move_voltage(rvoltage);
    left_front_motor.move_voltage(rvoltage);
    center_right.move_voltage(rvoltage);
    center_left.move_voltage(rvoltage);
    pros::delay(time);
    DriveStop();
}
void encoderDrive(int power, double traveldistance){
  double DistancetoRotations = 36000 * (traveldistance/circumference);
  rotation_left.reset_position();
  rotation_right.reset_position();
  right_front_motor.move_voltage(power);
  center_right.move_voltage(power);
  right_back_motor.move_voltage(power);
  left_front_motor.move_voltage(power);
  center_left.move_voltage(power);
  left_back_motor.move_voltage(power);
  while(rotation_left.get_position()< DistancetoRotations && rotation_right.get_position()< DistancetoRotations){
    pros::delay(15);
  }
  DriveStop();
}

void encoderTurn(int power, double traveldistance){
  double DistancetoRotations = 36000 * (traveldistance/circumference);
  rotation_left.reset_position();
  rotation_right.reset_position();
  right_front_motor.move_voltage(-power);
  center_right.move_voltage(-power);
  right_back_motor.move_voltage(-power);
  left_front_motor.move_voltage(power);
  center_left.move_voltage(power);
  left_back_motor.move_voltage(power);
  while(abs(rotation_left.get_position())< DistancetoRotations){
    pros::delay(15);
  }
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
