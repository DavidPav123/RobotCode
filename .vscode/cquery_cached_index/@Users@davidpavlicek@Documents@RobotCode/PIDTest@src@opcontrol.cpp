#include "main.h"
#include "motorDefs.hpp"

void opcontrol(){
  bool frontClawBool = false;
  bool rearClawBool = false;
  bool tilterBool = false;
  bool ringGrabberBool = false;
  bool motorBrakeBool = false;

  double turnImportance = 0.5;

  left_back_motor.set_brake_mode(MOTOR_BRAKE_COAST);
  right_front_motor.set_brake_mode(MOTOR_BRAKE_COAST);
  right_back_motor.set_brake_mode(MOTOR_BRAKE_COAST);
  left_front_motor.set_brake_mode(MOTOR_BRAKE_COAST);
  center_right.set_brake_mode(MOTOR_BRAKE_COAST);
  center_left.set_brake_mode(MOTOR_BRAKE_COAST);

  mobile_goal.set_brake_mode(MOTOR_BRAKE_BRAKE);

  while (1) {
    //Drive Control
    ///////////////////////////////////////////////////////////////////////////
    double turnVal = Controller1.get_analog(ANALOG_LEFT_X)/1.27;
    double forwardVal = Controller1.get_analog(ANALOG_LEFT_Y)/1.27;
    double turnVolts = turnVal * 120;
    double forwardVolts = forwardVal * 120 * (1 - (std::abs(turnVolts)/12000) * turnImportance);

    left_front_motor.move_voltage(forwardVolts + turnVolts);
    center_left.move_voltage(forwardVolts + turnVolts);
    left_back_motor.move_voltage(forwardVolts + turnVolts);
    right_front_motor.move_voltage(forwardVolts - turnVolts);
    center_right.move_voltage(forwardVolts - turnVolts);
    right_back_motor.move_voltage(forwardVolts - turnVolts);

    if(Controller1.get_digital_new_press(DIGITAL_UP)){
      if(motorBrakeBool == false){
        left_back_motor.set_brake_mode(MOTOR_BRAKE_HOLD);
        right_front_motor.set_brake_mode(MOTOR_BRAKE_HOLD);
        right_back_motor.set_brake_mode(MOTOR_BRAKE_HOLD);
        left_front_motor.set_brake_mode(MOTOR_BRAKE_HOLD);
        center_right.set_brake_mode(MOTOR_BRAKE_HOLD);
        center_left.set_brake_mode(MOTOR_BRAKE_HOLD);
        motorBrakeBool = true;
      }
      else if(motorBrakeBool == true){
        left_back_motor.set_brake_mode(MOTOR_BRAKE_COAST);
        right_front_motor.set_brake_mode(MOTOR_BRAKE_COAST);
        right_back_motor.set_brake_mode(MOTOR_BRAKE_COAST);
        left_front_motor.set_brake_mode(MOTOR_BRAKE_COAST);
        center_right.set_brake_mode(MOTOR_BRAKE_COAST);
        center_left.set_brake_mode(MOTOR_BRAKE_COAST);
        motorBrakeBool = false;
      }
    }
    ///////////////////////////////////////////////////////////////////////////

    //Mobile Goal Control
    ///////////////////////////////////////////////////////////////////////////
    if (Controller1.get_digital(DIGITAL_L2)){
      mobile_goal.move_voltage(12000);
    }
    else if (Controller1.get_digital(DIGITAL_L1)){
      mobile_goal.move_voltage(-12000);
    }
    else{
      mobile_goal.move_voltage(0);
    }

    if(Controller1.get_digital(DIGITAL_DOWN)){
      if(mobo_pot.get_value()< 1465){
        mobile_goal.move_voltage(-12000);
      }
      else{
        mobile_goal.move_voltage(0);
      }
    }
    ///////////////////////////////////////////////////////////////////////////

    //Intake
    ///////////////////////////////////////////////////////////////////////////
    if (Controller1.get_digital(DIGITAL_R1)){
      intake.move_voltage(-12000);
    }
    else if (Controller1.get_digital(DIGITAL_R2)){
      intake.move_voltage(12000);
    }
    else{
      intake.move_voltage(0);
    }
    ///////////////////////////////////////////////////////////////////////////

    //Pnuematics
    ///////////////////////////////////////////////////////////////////////////
    //Front Claw
    if(Controller1.get_digital_new_press(DIGITAL_X)){
      if(frontClawBool == false){
        front_mobile_goal.set_value(true);
        frontClawBool = true;
      }
      else if(frontClawBool == true){
        front_mobile_goal.set_value(false);
        frontClawBool = false;
      }
    }

    //Rear Claw
    if(Controller1.get_digital_new_press(DIGITAL_A)){
      if(rearClawBool == false){
        rear_mobile_goal.set_value(true);
        rearClawBool = true;
      }
      else if(rearClawBool == true){
        rear_mobile_goal.set_value(false);
        rearClawBool = false;
      }
    }

    //Tilter
    if(Controller1.get_digital_new_press(DIGITAL_B)){
      if(tilterBool == false){
        tilter.set_value(true);
        tilterBool = true;
      }
      else if(tilterBool == true){
        tilter.set_value(false);
        tilterBool = false;
      }
    }

    //Ring Grabber
    if(Controller1.get_digital_new_press(DIGITAL_Y)){
      if(ringGrabberBool == false){
        ring_grabber.set_value(true);
        ringGrabberBool = true;
      }
      else if(ringGrabberBool == true){
        ring_grabber.set_value(false);
        ringGrabberBool = false;
      }
    }
    ///////////////////////////////////////////////////////////////////////////
    pros::delay(10); //Delay to save resources
  }
}
