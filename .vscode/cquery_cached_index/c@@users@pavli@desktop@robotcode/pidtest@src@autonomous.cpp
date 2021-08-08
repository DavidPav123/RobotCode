#include "main.h"

//Drive PID
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constants
double kP = 0.5;
double kI = 0.0;
double kD = 0.0;

//Autonomous Settings
double desiredvalueDrive = 0;
bool resetDriveSensors = false;
bool enableDrivePID = false;

//Setting up running variables
int error; //SensorValue - desiredvalueDrive : Position
int prevError = 0; //Previous Position
int derivative; // error - prevError : Speed
int totalError = 0; //totalError + error
int averagePosition; //Average value of the rotation sensors
double lateralMotorPower; //Calculating motor power based on inputs and constants

int drivePID(){
  while(1){
  while(enableDrivePID){
    if (resetDriveSensors) {
      rotation_left.reset_position();
      rotation_right.reset_position();
      resetDriveSensors = false;
    }
    averagePosition = (abs(rotation_left.get_position()) + abs(rotation_right.get_position()))/2;
    error = desiredvalueDrive - averagePosition;
    totalError += error;
    derivative = error - prevError;
    lateralMotorPower = error * kP; //lateralMotorPower = error * kP + derivative * kD + totalError * kI;

    //Running motors based off calculated power
    left_back_motor.move_voltage(-lateralMotorPower);
    right_front_motor.move_voltage(-lateralMotorPower);
    right_back_motor.move_voltage(-lateralMotorPower);
    left_front_motor.move_voltage(-lateralMotorPower);
    center_right.move_voltage(-lateralMotorPower);
    center_left.move_voltage(-lateralMotorPower);

    prevError = error;

    //Enable for actual use, adjust the error based on acceptable range of offness
    /*if( error < 3 and error > -3 ){

    enableDrivePID = false;
    }*/
    pros::screen::print(pros::E_TEXT_LARGE, 3, "ENCODER: %3d", rotation_left.get_position());
    pros::screen::print(pros::E_TEXT_LARGE, 5, "ENCODER: %3d", rotation_right.get_position());
    pros::delay(15);
  }
  }return 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void autonomous(){
      pros::Task Driving(drivePID);
      resetDriveSensors = true;
      enableDrivePID = true;
      desiredvalueDrive = 72000;
      while(1){
        pros::delay(100);
        pros::screen::print(pros::E_TEXT_LARGE, 4, "ENCODER POSITION: %3d", abs(rotation_left.get_position()));
      }
      /*if(ProgSelect == 1.1){ Front Blue 1

      }*/
}
