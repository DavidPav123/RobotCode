#include "main.h"
#include "Functions.hpp"

//Drive PID
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constants

/*double kP = 0.2;
double kI = 0.0;
double kD = 0.0;
int max_speed = 10000;

//Autonomous Settings
double desiredvalueDrive = 0;
bool resetDriveSensors = false;
bool enableDrivePID = false;

//Setting up running variables
int left_error; //SensorValue - desiredvalueDrive : Position
int right_error; //SensorValue - desiredvalueDrive : Position
int left_prevError = 0; //Previous Position
int right_prevError = 0; //Previous Position
int left_derivative; // error - prevError : Speed
int right_derivative; // error - prevError : Speed
int left_totalError = 0; //totalError + error
int right_totalError = 0; //totalError + error
int left_averagePosition; //Average value of the rotation sensors
int right_averagePosition; //Average value of the rotation sensors
double left_lateralMotorPower; //Calculating motor power based on inputs and constants
double right_lateralMotorPower; //Calculating motor power based on inputs and constants

int drivePID(){
  while(1){
  while(enableDrivePID){
    if (resetDriveSensors) {
      rotation_left.reset_position();
      rotation_right.reset_position();
      resetDriveSensors = false;
    }
    left_averagePosition = (abs(rotation_left.get_position()));
    right_averagePosition = (abs(rotation_right.get_position()));
    left_error = desiredvalueDrive - left_averagePosition;
    right_error = desiredvalueDrive - right_averagePosition;
    left_totalError += left_error;
    right_totalError += right_error;
    left_derivative = left_error - left_prevError;
    right_derivative = right_error - right_prevError;
    left_lateralMotorPower = (left_error * kP + left_derivative * kD + left_totalError * kI); //lateralMotorPower = error * kP + derivative * kD + totalError * kI;
    if(left_lateralMotorPower > max_speed){
      left_lateralMotorPower = max_speed;
    }
    right_lateralMotorPower = (right_error * kP + right_derivative * kD + right_totalError * kI);
    if(right_lateralMotorPower > max_speed){
      right_lateralMotorPower = max_speed;
    }
    //Running motors based off calculated power
    left_back_motor.move_voltage(left_lateralMotorPower);
    right_front_motor.move_voltage(left_lateralMotorPower);
    right_back_motor.move_voltage(-left_lateralMotorPower);
    left_front_motor.move_voltage(right_lateralMotorPower);
    center_right.move_voltage(right_lateralMotorPower);
    center_left.move_voltage(right_lateralMotorPower);

    left_prevError = left_error;
    right_prevError = right_error;

  //Enable for actual use, adjust the error based on acceptable range of offness

    //if( right_error < 3 and right_error > -3 ){

    //enableDrivePID = false;
  //}
    pros::screen::print(pros::E_TEXT_LARGE, 3, "ENCODER: %3d", rotation_left.get_position());
    pros::screen::print(pros::E_TEXT_LARGE, 5, "ENCODER: %3d", rotation_right.get_position());
    pros::delay(15);
  }
  }return 1;
}

void driveUsingPID(int traveldistance){
  double DistancetoRotations = 36000 * (traveldistance/circumference);
  desiredvalueDrive = DistancetoRotations; //One rotation is 36000
  resetDriveSensors = true;
  enableDrivePID = true;
  pros::Task Driving(drivePID);
  while(enableDrivePID == true){
    pros::delay(20);
  }
  DriveStop();
}*/

void autonomous(){
  front_mobile_goal.set_value(false);
  encoderDrive(12000,45);
  front_mobile_goal.set_value(true);
  encoderDrive(-12000, 30);
  timeDrive(-11000,1250);
  encoderDrive(12000, 3.5);
  rear_mobile_goal.set_value(false);
  pros::delay(1000);
  encoderTurn(-11000,11);
  pros::delay(500);
  encoderDrive(-12000,60);

  //own6
  /*front_mobile_goal.set_value(false);
  encoderDrive(12000,45);
  front_mobile_goal.set_value(true);
  encoderDrive(-12000, 30);
front_mobile_goal.set_value(false);
  pros::delay(250);
  timeDrive(-11000,1250);
  encoderDrive(12000, 5);
  rear_mobile_goal.set_value(false);
  pros::delay(1000);
  encoderTurn(-11000,7);
  encoderDrive(-12000,14);
  rear_mobile_goal.set_value(true);
  encoderDrive(12000,15);
  intake.move_voltage(12000);*/

  //Upside Auto
  /*front_mobile_goal.set_value(false);
  encoderDrive(12000,42);
  front_mobile_goal.set_value(true);
  encoderDrive(-12000,30);
  pros::delay(500);
  encoderTurn(-9000, 10.5);
  rear_mobile_goal.set_value(false);
  encoderDrive(-12000, 20);
  rear_mobile_goal.set_value(true);
  intake.move_voltage(12000);
  encoderDrive(12000, 5);
  encoderTurn(12000,2);
  encoderDrive(12000, 35);
  intake.move_voltage(0);*/


  /*if(ProgSelect == 1.1){ Front Blue 1

  }*/
  pros::delay(100);
}
