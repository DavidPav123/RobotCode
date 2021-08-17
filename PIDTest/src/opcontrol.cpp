#include "main.h"
#include "MotorDefs.hpp"

void opcontrol(){
  double turnImportance = 0.5;
  bool centerWheelCoupled = true;
  //bool clawstate = false;
  ring_manipulator.set_value(true);
  center_shifter.set_value(false);

  mobile_goal_left.set_brake_mode(MOTOR_BRAKE_BRAKE);
  mobile_goal_right.set_brake_mode(MOTOR_BRAKE_BRAKE);
  //ring_pot.calibrate();

  while (1) {
    //pros::screen::erase();
    //pros::screen::print(pros::E_TEXT_LARGE, 4, "Value: %5d",mobo_pot.get_value());
    //Drive Control
    ///////////////////////////////////////////////////////////////////////////
    double turnVal = Controller1.get_analog(ANALOG_LEFT_X)/1.27;
    double forwardVal = Controller1.get_analog(ANALOG_LEFT_Y)/1.27;
    double turnVolts = turnVal * 120;
    double forwardVolts = forwardVal * 120 * (1 - (std::abs(turnVolts)/12000) * turnImportance);

    if(centerWheelCoupled == true){
      left_back_motor.move_voltage(forwardVolts + turnVolts);
      left_front_motor.move_voltage(forwardVolts + turnVolts);
      right_back_motor.move_voltage(forwardVolts - turnVolts);
      right_front_motor.move_voltage(forwardVolts - turnVolts);
    }
    else{
      left_back_motor.move_voltage(forwardVolts + turnVolts);
      left_front_motor.move_voltage(forwardVolts + turnVolts);
      right_back_motor.move_voltage(forwardVolts - turnVolts);
      right_front_motor.move_voltage(forwardVolts - turnVolts);
      center_right.move_voltage(forwardVolts - turnVolts);
      center_left.move_voltage(forwardVolts + turnVolts);
      center_left.set_brake_mode(MOTOR_BRAKE_COAST);
      center_right.set_brake_mode(MOTOR_BRAKE_COAST);
    }
    ///////////////////////////////////////////////////////////////////////////

    //Lift Control
    ///////////////////////////////////////////////////////////////////////////
    if(centerWheelCoupled == false){
      if (Controller1.get_digital(DIGITAL_R2)){
        center_left.move_voltage(-12000);
        center_right.move_voltage(12000);
      }
      else if (Controller1.get_digital(DIGITAL_R1)){
        center_left.move_voltage(12000);
        center_right.move_voltage(-12000);
      }
      else{
        center_left.move_voltage(0);
        center_right.move_voltage(0);
        center_left.set_brake_mode(MOTOR_BRAKE_BRAKE);
        center_right.set_brake_mode(MOTOR_BRAKE_BRAKE);
      }
    }
    ///////////////////////////////////////////////////////////////////////////

    //Mobile Goal Control
    ///////////////////////////////////////////////////////////////////////////
    if (Controller1.get_digital(DIGITAL_L2)){
      mobile_goal_left.move_voltage(12000);
      mobile_goal_right.move_voltage(12000);
    }
    else if (Controller1.get_digital(DIGITAL_L1)){
      mobile_goal_left.move_voltage(-12000);
      mobile_goal_right.move_voltage(-12000);
    }
    else{
      mobile_goal_left.move_voltage(0);
      mobile_goal_right.move_voltage(0);
    }
    ///////////////////////////////////////////////////////////////////////////

    //Pnuematics
    ///////////////////////////////////////////////////////////////////////////
    if(Controller1.get_digital(DIGITAL_UP)){
      center_shifter.set_value(true);
      centerWheelCoupled = true;
    }
    else if(Controller1.get_digital(DIGITAL_DOWN)){
      center_shifter.set_value(false);
      centerWheelCoupled = false;
    }

    if(Controller1.get_digital(DIGITAL_A)){
      ring_manipulator.set_value(false);
    }
    else{
      ring_manipulator.set_value(true);
    }

    ///////////////////////////////////////////////////////////////////////////
    pros::delay(10);
  }
}
