#include "main.h"
#include "Functions.hpp"
//Drive PID
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constants
double tkP = 0.0;
double tkI = 0.0;
double tkD = 0.0;

//Autonomous Settings
double desiredvalueTurn = 0;
bool resetDriveSensors = false;
bool enableTurnPID = false;

//Setting up running variables
int terror; //SensorValue - desiredvalueDrive : Position
int tprevError = 0; //Previous Position
int tderivative; // error - prevError : Speed
int ttotalError = 0; //totalError + error
int taveragePosition; //Average value of the rotation sensors
double tlateralMotorPower; //Calculating motor power based on inputs and constants

int turnPID(){
  while(1){
  while(enableTurnPID){
    if (resetDriveSensors) {
      rotation_left.reset_position();
      rotation_right.reset_position();
      resetDriveSensors = false;
    }
    taveragePosition = (abs(rotation_left.get_position()) + abs(rotation_right.get_position()))/2;
    terror = desiredvalueTurn - taveragePosition;
    ttotalError += terror;
    tderivative = terror - tprevError;
    tlateralMotorPower = terror * tkP; //lateralMotorPower = error * kP + derivative * kD + totalError * kI;

    //Running motors based off calculated power
    right_front_motor.move_voltage(lateralMotorPower);
    center_right.move_voltage(lateralMotorPower);
    right_back_motor.move_voltage(lateralMotorPower);
    left_front_motor.move_voltage(-lateralMotorPower);
    center_left.move_voltage(-lateralMotorPower);
    left_back_motor.move_voltage(-lateralMotorPower);

    tprevError = terror;
    //Enable for actual use, adjust the error based on acceptable range of offness
    /*if( error < 3 and error > -3 ){

    enableTurnPID = false;
    }*/
    pros::screen::print(pros::E_TEXT_LARGE, 3, "ENCODER: %3d", rotation_left.get_position());
    pros::screen::print(pros::E_TEXT_LARGE, 5, "ENCODER: %3d", rotation_right.get_position());
    pros::delay(15);
  }
  }return 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void turnUsingPID(int traveldistance){
  double DistancetoRotations = 36000 * (traveldistance/circumference);
  desiredvalueDrive = DistancetoRotations; //One rotation is 36000
  resetDriveSensors = true;
  enableDrivePID = true;
  pros::Task Turning(turnPID);
  while(enableDrivePID == true){
    pros::delay(20);
  }
  DriveStop();
}

void autonomous(){
  pros::Task Driving(drivePID);
  resetDriveSensors = true;
  enableDrivePID = true;
  desiredvalueDrive = 72000;
  while(1){
    pros::delay(100);
  }
  /*if(ProgSelect == 1.1){ Front Blue 1

  }*/
}
