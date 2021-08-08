/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * Copyright (c) 2017-2021, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convienent for most student programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS

#include "api.h"

/**
 * You should add more #includes here
 */
 #include "cmath"
//#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
// using namespace pros;
// using namespace pros::literals;
// using namespace okapi;

#define LEFT_BACK_MOTOR_PORT 20
#define LEFT_FRONT_MOTOR_PORT 19
#define CENTER_LEFT_PORT 17
#define CENTER_RIGHT_PORT 18
#define RIGHT_FRONT_MOTOR_PORT 11
#define RIGHT_BACK_MOTOR_PORT 12
#define RINGLY_DINGLER_PORT 13
#define MOBILE_GOAL_PORT 14
#define ROTATION_LEFT_PORT 6
#define ROTATION_RIGHT_PORT 15
#define MOBO_POT_PORT 1
#define CENTER_SHIFTER_PORT 2
#define RING_MANIPULATOR_PORT 3
#define DRIVE_SPEED_SHIFTER_PORT 4
#define RING_POT_PORT 5

extern pros::Controller Controller1;
extern pros::Motor left_back_motor;
extern pros::Motor left_front_motor;
extern pros::Motor center_left;
extern pros::Motor center_right;
extern pros::Motor right_back_motor;
extern pros::Motor right_front_motor;
extern pros::Motor ringly_dingler;
extern pros::Motor mobile_goal;
extern pros::Rotation rotation_left;
extern pros::Rotation rotation_right;
extern pros::ADIAnalogIn mobo_pot;
extern pros::ADIDigitalOut center_shifter;
extern pros::ADIDigitalOut ring_manipulator;
extern pros::ADIDigitalOut drive_speed_shifter;
extern pros::ADIAnalogIn ring_pot;

extern bool center_shifter_state;
extern bool drive_speed_shifter_state;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
