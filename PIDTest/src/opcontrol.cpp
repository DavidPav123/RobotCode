#include "main.h"
#include "MotorDefs.hpp"

void opcontrol(){
  double turnImportance = 0.5;

  rear_mobile_goal.set_value(true);

  mobile_goal.set_brake_mode(MOTOR_BRAKE_BRAKE);

  while (1) {
    //pros::screen::erase();
    //pros::screen::print(pros::E_TEXT_LARGE, 4, "Value: %5d",mobo_pot.get_value());
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
    ///////////////////////////////////////////////////////////////////////////

    //Intake
    ///////////////////////////////////////////////////////////////////////////
    if (Controller1.get_digital(DIGITAL_R2)){
      intake.move_voltage(12000);
    }
    else if (Controller1.get_digital(DIGITAL_R1)){
      intake.move_voltage(-12000);
    }
    else{
      intake.move_voltage(0);
    }
    ///////////////////////////////////////////////////////////////////////////

    //Pnuematics
    ///////////////////////////////////////////////////////////////////////////
    //Front Claw
    if(Controller1.get_digital(DIGITAL_X)){
      front_mobile_goal.set_value(true);
    }
    else if(Controller1.get_digital(DIGITAL_Y)){
      front_mobile_goal.set_value(false);
    }

    //Rear Claw
    if(Controller1.get_digital(DIGITAL_A)){
      rear_mobile_goal.set_value(false);
    }
    else{
      rear_mobile_goal.set_value(true);
    }
    ///////////////////////////////////////////////////////////////////////////
    pros::delay(10);
  }
}
