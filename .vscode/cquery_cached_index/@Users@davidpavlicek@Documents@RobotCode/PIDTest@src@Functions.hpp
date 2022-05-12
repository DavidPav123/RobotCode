#include "main.h"

//Setting up variables for functions
double wheelDiameterIN  = 3.25; //wheelDiameter is the measurement of a wheel from edge to edge in inches
double circumference = wheelDiameterIN * M_PI; //M_PI is math function that stands for PI

//Drive Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DriveStop(pros::motor_brake_mode_e_t mode){
  left_back_motor.move_voltage(0);
  right_front_motor.move_voltage(0);
  right_back_motor.move_voltage(0);
  left_front_motor.move_voltage(0);
  center_right.move_voltage(0);
  center_left.move_voltage(0);
  left_back_motor.set_brake_mode(mode);
  right_front_motor.set_brake_mode(mode);
  right_back_motor.set_brake_mode(mode);
  left_front_motor.set_brake_mode(mode);
  center_right.set_brake_mode(mode);
  center_left.set_brake_mode(mode);
}

void timeDrive(int rvoltage, int time){
  left_back_motor.move_voltage(rvoltage);
  right_front_motor.move_voltage(rvoltage);
  right_back_motor.move_voltage(rvoltage);
  left_front_motor.move_voltage(rvoltage);
  center_right.move_voltage(rvoltage);
  center_left.move_voltage(rvoltage);
  pros::delay(time);
}

void curveTurnRight(int speed, double curveValue){
  left_front_motor.move_voltage(speed);
  center_left.move_voltage(speed);
  left_back_motor.move_voltage(speed);
  right_front_motor.move_voltage(speed * curveValue);
  center_right.move_voltage(speed * curveValue);
  right_back_motor.move_voltage(speed * curveValue);
}

void curveTurnLeft(int speed, double curveValue){
  left_front_motor.move_voltage(-speed);
  center_left.move_voltage(-speed);
  left_back_motor.move_voltage(-speed);
  right_front_motor.move_voltage(-speed * curveValue);
  center_right.move_voltage(-speed * curveValue);
  right_back_motor.move_voltage(-speed * curveValue);
}

void encoderDrive(int power, double travelDistance){
  double DistancetoRotations = 36000 * (travelDistance/circumference);
  rotation_left.reset_position();
  rotation_right.reset_position();
  right_front_motor.move_voltage(power);
  center_right.move_voltage(power);
  right_back_motor.move_voltage(power);
  left_front_motor.move_voltage(power);
  center_left.move_voltage(power);
  left_back_motor.move_voltage(power);
  while(rotation_left.get_position()< DistancetoRotations && rotation_right.get_position()< DistancetoRotations){
    pros::delay(10);
  }
  DriveStop(MOTOR_BRAKE_BRAKE);
}

void encoderTurn(int power, double travelDistance){
  double DistancetoRotations = 36000 * (travelDistance/circumference);
  rotation_left.reset_position();
  rotation_right.reset_position();
  right_front_motor.move_voltage(-power);
  center_right.move_voltage(-power);
  right_back_motor.move_voltage(-power);
  left_front_motor.move_voltage(power);
  center_left.move_voltage(power);
  left_back_motor.move_voltage(power);
  while(abs(rotation_left.get_position())< DistancetoRotations){
    pros::delay(10);
  }
  DriveStop(MOTOR_BRAKE_BRAKE);
}

void encoderCurveRight(int power, double traveldistance, double curveValue){
  double DistancetoRotations = 36000 * (traveldistance/circumference);
  rotation_left.reset_position();
  rotation_right.reset_position();
  right_front_motor.move_voltage(power);
  center_right.move_voltage(power);
  right_back_motor.move_voltage(power);
  left_front_motor.move_voltage(power * curveValue);
  center_left.move_voltage(power * curveValue);
  left_back_motor.move_voltage(power * curveValue);
  while(abs(rotation_left.get_position())< DistancetoRotations){
    pros::delay(15);
  }
  DriveStop(MOTOR_BRAKE_BRAKE);
}

void encoderCurveLeft(int power, double traveldistance, double curveValue){
  double DistancetoRotations = 36000 * (traveldistance/circumference);
  rotation_left.reset_position();
  rotation_right.reset_position();
  right_front_motor.move_voltage(power * curveValue);
  center_right.move_voltage(power * curveValue);
  right_back_motor.move_voltage(power * curveValue);
  left_front_motor.move_voltage(power);
  center_left.move_voltage(power);
  left_back_motor.move_voltage(power);
  while(abs(rotation_left.get_position())< DistancetoRotations){
    pros::delay(15);
  }
  DriveStop(MOTOR_BRAKE_BRAKE);
}
///////////////////////////////////////////////////////////////////////////

//Mobile Goal Functions
///////////////////////////////////////////////////////////////////////////
void MobileGoalUp(){
  while(mobo_pot.get_value() < 1100){
    mobile_goal.move_voltage(-12000);
  }
  mobile_goal.move_voltage(0);
  mobile_goal.set_brake_mode(MOTOR_BRAKE_BRAKE);
}

void MobileGoalDown(){
  while(mobo_pot.get_value() > 10){
    mobile_goal.move_voltage(12000);
  }
  mobile_goal.move_voltage(0);
  mobile_goal.set_brake_mode(MOTOR_BRAKE_BRAKE);
}

//Function to acutate pistions so you don't have to remember which state does what
void RearClawUp(){
  rear_mobile_goal.set_value(false);
}
void RearClawDown(){
  rear_mobile_goal.set_value(true);
}
void FrontClawClose(){
  front_mobile_goal.set_value(true);
}
void FrontClawOpen(){
  front_mobile_goal.set_value(false);
}
///////////////////////////////////////////////////////////////////////////

//Intake Functions
///////////////////////////////////////////////////////////////////////////
void intakeIn(int speed){
  intake.move_voltage(-speed);
}
///////////////////////////////////////////////////////////////////////////

//Chassis builders
///////////////////////////////////////////////////////////////////////////
std::shared_ptr<OdomChassisController> chassis = ChassisControllerBuilder()
.withMotors({11,12,13}, {17,18,19}) // left motors, right motors
.withGains(
  {0.00042, 0.000035, 0.0000009}, // distance controller gains
  {0.001, 0.0009, 0.000009}, // turn controller gains
  {0.00042, 0.000035, 0.0000009}  // angle controller gains (helps drive straight)
)
.withSensors(
  RotationSensor(2), // left encoder
  RotationSensor(3, true)  // right encoder
)
// green gearset, tracking wheel diameter (3.25 in), track (11 in), and TPR (360)
.withDimensions(AbstractMotor::gearset::blue, {{3.25_in, 12.915_in}, imev5BlueTPR})
.withOdometry()// use the same scales as the chassis (above)
.buildOdometry(); // build an odometry chassis
///////////////////////////////////////////////////////////////////////////
