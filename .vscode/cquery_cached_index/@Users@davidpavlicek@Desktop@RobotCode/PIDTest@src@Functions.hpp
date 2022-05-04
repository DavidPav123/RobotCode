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
void DriveStop1(){
  left_back_motor.move_voltage(0);
  right_front_motor.move_voltage(0);
  right_back_motor.move_voltage(0);
  left_front_motor.move_voltage(0);
  center_right.move_voltage(0);
  center_left.move_voltage(0);
  left_back_motor.set_brake_mode(MOTOR_BRAKE_COAST);
  right_front_motor.set_brake_mode(MOTOR_BRAKE_COAST);
  right_back_motor.set_brake_mode(MOTOR_BRAKE_COAST);
  left_front_motor.set_brake_mode(MOTOR_BRAKE_COAST);
  center_right.set_brake_mode(MOTOR_BRAKE_COAST);
  center_left.set_brake_mode(MOTOR_BRAKE_COAST);
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
void turnRight(int speed){
  right_front_motor.move_voltage(-speed);
  center_right.move_voltage(-speed);
  right_back_motor.move_voltage(-speed);
  left_front_motor.move_voltage(speed);
  center_left.move_voltage(speed);
  left_back_motor.move_voltage(speed);
}
void testturnright(int speed){
  right_front_motor.move_velocity(-speed);
  center_right.move_velocity(-speed);
  right_back_motor.move_velocity(-speed);
  left_front_motor.move_velocity(speed);
  center_left.move_velocity(speed);
  left_back_motor.move_velocity(speed);

}
void testturnleft(int speed){
  right_front_motor.move_velocity(speed);
  center_right.move_velocity(speed);
  right_back_motor.move_velocity(speed);
  left_front_motor.move_velocity(-speed);
  center_left.move_velocity(-speed);
  left_back_motor.move_velocity(-speed);

}
void hturnRight(int speed){
  left_front_motor.move_voltage(speed);
  center_left.move_voltage(speed);
  left_back_motor.move_voltage(speed);
  right_front_motor.move_voltage(speed * 0.255);
  center_right.move_voltage(speed * 0.255);
  right_back_motor.move_voltage(speed * 0.255);
}
void turnLeft(int speed){
  right_front_motor.move_voltage(speed);
  center_right.move_voltage(speed);
  right_back_motor.move_voltage(speed);
  left_front_motor.move_voltage(-speed);
  center_left.move_voltage(-speed);
  left_back_motor.move_voltage(-speed);
}
void hturnLeft(int speed){
  left_front_motor.move_voltage(-speed);
  center_left.move_voltage(-speed);
  left_back_motor.move_voltage(-speed);
  right_front_motor.move_voltage(-speed * 0.255);
  center_right.move_voltage(-speed * 0.255);
  right_back_motor.move_voltage(-speed * 0.255);
}
void hhturnLeft(int speed){
  left_front_motor.move_voltage(-speed);
  center_left.move_voltage(-speed);
  left_back_motor.move_voltage(-speed);
  right_front_motor.move_voltage(-speed * 075);
  center_right.move_voltage(-speed * 0.75);
  right_back_motor.move_voltage(-speed * 0.75);
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

void encoderTurn2(int power, double traveldistance){
  double DistancetoRotations = 36000 * (traveldistance/circumference);
  rotation_left.reset_position();
  rotation_right.reset_position();
  right_front_motor.move_voltage(power);
  center_right.move_voltage(power);
  right_back_motor.move_voltage(power);
  left_front_motor.move_voltage(power * 0.64);
  center_left.move_voltage(power * 0.64);
  left_back_motor.move_voltage(power * 0.4);
  while(abs(rotation_left.get_position())< DistancetoRotations){
    pros::delay(15);
  }
  DriveStop();
}

void encoderTurn3(int power, double traveldistance){
  double DistancetoRotations = 36000 * (traveldistance/circumference);
  rotation_left.reset_position();
  rotation_right.reset_position();
  right_front_motor.move_voltage(power * .5);
  center_right.move_voltage(power * .5);
  right_back_motor.move_voltage(power * .5);
  left_front_motor.move_voltage(power);
  center_left.move_voltage(power);
  left_back_motor.move_voltage(power);
  while(abs(rotation_left.get_position())< DistancetoRotations){
    pros::delay(15);
  }
  DriveStop();
}

void encoderTurn4(int power, double traveldistance){
  double DistancetoRotations = 36000 * (traveldistance/circumference);
  rotation_left.reset_position();
  rotation_right.reset_position();
  right_front_motor.move_voltage(power );
  center_right.move_voltage(power );
  right_back_motor.move_voltage(power );
  left_front_motor.move_voltage(power * .5);
  center_left.move_voltage(power * .5);
  left_back_motor.move_voltage(power * .5);
  while(abs(rotation_left.get_position())< DistancetoRotations){
    pros::delay(15);
  }
  DriveStop();
}

void encoderTurn1(int power, double traveldistance){
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
  DriveStop1();
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
void intakeIn(int speed){
  intake.move_voltage(-speed);
}
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
  RotationSensor(2), // left encoder Idk if these are correct its something like this
  RotationSensor(3, true)  // right encoder
)
// green gearset, tracking whe5l diameter (3.25 in), track (11 in), and TPR (360)
.withDimensions(AbstractMotor::gearset::blue, {{3.25_in, 12.915_in}, quadEncoderTPR}) //I don't know that the tpr for the encoders is so youll have to figure it out also the track is the distance between the who wheels
.withOdometry()// use the same scales as the chassis (above)
.buildOdometry(); // build an odometry chassis


std::shared_ptr<OdomChassisController> chassis1 = ChassisControllerBuilder()
.withMotors({10,19,12}, {15,2,1}) // left motors, right motors
.withGains(
  {0.00064, 0.0003, 0.0000008}, // distance controller gains
  {0.0013, 0.0003, 0.0000008}, // turn controller gains
  {0.001, 0.0003, 0.0000008}  // angle controller gains (helps drive straight)
)
.withSensors(
  RotationSensor(17), // left encoder Idk if these are correct its something like this
  RotationSensor(13, true)  // right encoder
)
// green gearset, tracking wheel diameter (3.25 in), track (11 in), and TPR (360)
.withDimensions(AbstractMotor::gearset::blue, {{3.25_in, 14.87_in}, quadEncoderTPR}) //I don't know that the tpr for the encoders is so youll have to figure it out also the track is the distance between the who wheels
.withOdometry() // use the same scales as the chassis (above)
.buildOdometry(); // build an odometry chassis


std::shared_ptr<OdomChassisController> chassis2 = ChassisControllerBuilder()
.withMotors({10,19,12}, {15,2,1}) // left motors, right motors
.withGains(
  {0.0006, 0.0003, 0.0000008}, // distance controller gains
  {0.00085, 0.0003, 0.0000008}, // turn controller gains
  {0.001, 0.0003, 0.0000008}  // angle controller gains (helps drive straight)
)
.withSensors(
  RotationSensor(17), // left encoder Idk if these are correct its something like this
  RotationSensor(13, true)  // right encoder
)
// green gearset, tracking wheel diameter (3.25 in), track (11 in), and TPR (360)
.withDimensions(AbstractMotor::gearset::blue, {{3.25_in, 14.87_in}, quadEncoderTPR}) //I don't know that the tpr for the encoders is so youll have to figure it out also the track is the distance between the who wheels
.withOdometry() // use the same scales as the chassis (above)
.buildOdometry(); // build an odometry chassis

///////////////////////////////////////////////////////////////////////////
