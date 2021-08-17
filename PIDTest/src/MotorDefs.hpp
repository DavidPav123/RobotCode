#include "main.h"

pros::Controller Controller1 (CONTROLLER_MASTER);
pros::Motor left_back_motor (LEFT_BACK_MOTOR_PORT, MOTOR_GEARSET_18);
pros::Motor left_front_motor (LEFT_FRONT_MOTOR_PORT, MOTOR_GEARSET_18,true);
pros::Motor center_left (CENTER_LEFT_PORT, MOTOR_GEARSET_18,true);
pros::Motor center_right (CENTER_RIGHT_PORT, MOTOR_GEARSET_18);
pros::Motor right_back_motor (RIGHT_BACK_MOTOR_PORT, MOTOR_GEARSET_18,true);
pros::Motor right_front_motor (RIGHT_FRONT_MOTOR_PORT, MOTOR_GEARSET_18);
pros::Motor mobile_goal_left (MOBILE_GOAL_LEFT_PORT, MOTOR_GEARSET_36);
pros::Motor mobile_goal_right (MOBILE_GOAL_RIGHT_PORT, MOTOR_GEARSET_36,true);
pros::Rotation rotation_left (ROTATION_LEFT_PORT);
pros::Rotation rotation_right (ROTATION_RIGHT_PORT);
pros::ADIAnalogIn mobo_pot (MOBO_POT_PORT);
pros::ADIDigitalOut center_shifter (CENTER_SHIFTER_PORT);
pros::ADIDigitalOut ring_manipulator (RING_MANIPULATOR_PORT);
pros::ADIDigitalOut drive_speed_shifter (DRIVE_SPEED_SHIFTER_PORT);
pros::ADIAnalogIn ring_pot (RING_POT_PORT);
