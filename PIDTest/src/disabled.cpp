#include "main.h"

void disabled(){
  mobile_goal.set_brake_mode(MOTOR_BRAKE_BRAKE);
  tilter.set_value(true);
  front_mobile_goal.set_value(true);
}
