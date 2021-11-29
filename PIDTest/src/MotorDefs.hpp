#include "main.h"

pros::Controller Controller1 (CONTROLLER_MASTER);
pros::Motor left_front_motor (LEFT_FRONT_MOTOR_PORT, MOTOR_GEARSET_18,true);
pros::Motor center_left (CENTER_LEFT_PORT, MOTOR_GEARSET_18,true);
pros::Motor left_back_motor (LEFT_BACK_MOTOR_PORT, MOTOR_GEARSET_18);
pros::Motor right_front_motor (RIGHT_FRONT_MOTOR_PORT, MOTOR_GEARSET_18);
pros::Motor center_right (CENTER_RIGHT_PORT, MOTOR_GEARSET_18);
pros::Motor right_back_motor (RIGHT_BACK_MOTOR_PORT, MOTOR_GEARSET_18,true);
pros::Motor mobile_goal (MOBILE_GOAL_PORT, MOTOR_GEARSET_36);
pros::Motor intake (INTAKE_PORT, MOTOR_GEARSET_6,true);
pros::Rotation rotation_left (ROTATION_LEFT_PORT);
pros::Rotation rotation_right (ROTATION_RIGHT_PORT);
pros::ADIAnalogIn mobo_pot (MOBO_POT_PORT);
pros::ADIDigitalOut front_mobile_goal (FRONT_MOBILE_GOAL_PORT);
pros::ADIDigitalOut rear_mobile_goal (REAR_MOBILE_GOAL_PORT);
