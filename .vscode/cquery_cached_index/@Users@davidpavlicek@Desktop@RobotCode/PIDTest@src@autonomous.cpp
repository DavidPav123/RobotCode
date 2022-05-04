#include "Functions.hpp"

void my_task_fn(void* param) {
  FrontClawOpen();
  ring_grabber.set_value(true);
  tilter.set_value(false);
  pros::delay(150);
  ring_grabber.set_value(false);
}

void autonomous(){
  //Blue Side Autos
  if(ProgSelect == 11){//Blue Right neutral + Alliance + Rings
    mobile_goal.set_brake_mode(MOTOR_BRAKE_HOLD);
    pros::Task my_task(my_task_fn);
    encoderDrive(12000,40);
    FrontClawClose();
    mobile_goal.move_voltage(10000);
    pros::delay(500);
    mobile_goal.move_voltage(0);
    encoderDrive(-12000,40);
    timeDrive(-6000,1000);
    DriveStop();
    RearClawDown();
    encoderDrive(10000, 24);
    pros::delay(500);
    encoderTurn(-7000, 10.4);
    pros::delay(500);
    timeDrive(-8000,1250);
    DriveStop();
    RearClawUp();
    pros::delay(750);
    encoderDrive(8000, 2);
    intakeIn(8000);
    mobile_goal.move_voltage(-12000);
    encoderTurn(8000, 12);
    pros::delay(500);
    mobile_goal.move_voltage(0);
    encoderDrive(5000, 45);
    timeDrive(-12000, 1250);
    intake.move_voltage(0);
    DriveStop();
  }

  if(ProgSelect == 12){ //Right Nuetral Spin
    mobile_goal.set_brake_mode(MOTOR_BRAKE_HOLD);
    pros::Task my_task(my_task_fn);
    encoderDrive(12000,40);
    FrontClawClose();
    mobile_goal.move_voltage(-12000);
    encoderTurn(-12000, 12);
    mobile_goal.move_voltage(0);
    pros::delay(750);
    timeDrive(12000,1000);
    DriveStop();
  }

  if(ProgSelect == 13){ //RF -> Center
    FrontClawOpen();
    encoderDrive(10000, 14.5);
    pros::delay(500);
    encoderTurn(-7500, 3.5);
    pros::delay(500);
    encoderDrive(12000, 33);
    RearClawDown();
    FrontClawClose();
    pros::delay(500);
    encoderDrive(-12000, 40);
    timeDrive(-7000, 500);
    DriveStop();
    RearClawUp();
    encoderTurn(8000, 8);
    intakeIn(10000);
  }

  if(ProgSelect == 14){ //Center -> Alliance -> Rings
    mobile_goal.set_brake_mode(MOTOR_BRAKE_HOLD);
    pros::Task my_task(my_task_fn);
    encoderDrive(12000,53);
    FrontClawClose();
    pros::delay(500);
    encoderDrive(-12000, 30);
    RearClawDown();
    pros::delay(500);
    encoderTurn(-7500, 5.5);
    pros::delay(500);
    encoderDrive(-12000, 15);
    pros::delay(500);
    timeDrive(-7000, 1000);
    DriveStop();
    RearClawUp();
    pros::delay(750);
    encoderDrive(8000, 2);
    intakeIn(8000);
    mobile_goal.move_voltage(-12000);
    encoderTurn(8000, 12);
    pros::delay(500);
    mobile_goal.move_voltage(0);
    encoderDrive(4000, 45);
    timeDrive(-12000, 1250);
    intake.move_voltage(0);
    DriveStop();
  }

  if(ProgSelect == 15){ //CF -> Right Nuetral
    FrontClawOpen();
    encoderDrive(10000, 2);
    encoderTurn3(12000, 25);
    encoderDrive(12000, 18);
    FrontClawClose();
    pros::delay(500);
    encoderDrive(-12000, 23);
    RearClawDown();
    pros::delay(500);
    encoderTurn(-7500, 11);
    pros::delay(500);
    encoderDrive(-12000, 20);
    pros::delay(500);
    timeDrive(-7000,1000);
    DriveStop();
    RearClawUp();
    pros::delay(750);
    encoderDrive(8000, 2);
    intakeIn(8000);
    mobile_goal.move_voltage(-12000);
    encoderTurn(8000, 12);
    pros::delay(500);
    mobile_goal.move_voltage(0);
    encoderDrive(5000, 45);
    timeDrive(-12000, 1250);
    intake.move_voltage(0);
    DriveStop();
  }

  if(ProgSelect == 21){ //Left Nutral + Alliance Goal
    mobile_goal.set_brake_mode(MOTOR_BRAKE_HOLD);
    pros::Task my_task(my_task_fn);
    encoderDrive(12000,40);
    FrontClawClose();
    mobile_goal.move_voltage(10000);
    RearClawDown();
    pros::delay(500);
    mobile_goal.move_voltage(0);
    encoderDrive(-12000,40);
    timeDrive(-6000,1000);
    DriveStop();
    pros::delay(500);
    encoderDrive(8000, 4);
    pros::delay(500);
    encoderTurn(-8000, 8.5);
    pros::delay(500);
    timeDrive(-6000,1000);
    DriveStop();
    RearClawUp();
    pros::delay(750);
    encoderDrive(12000, 5);
    intakeIn(10000);
  }

  if(ProgSelect == 22){ //Center Goal Left Side
    mobile_goal.set_brake_mode(MOTOR_BRAKE_HOLD);
    intakeIn(12000);
    pros::Task my_task(my_task_fn);
    encoderDrive(12000,60);
    FrontClawClose();
    mobile_goal.move_voltage(10000);
    pros::delay(500);
    encoderDrive(-12000,55);
    mobile_goal.move_voltage(0);
  }

  if(ProgSelect == 23){ //FL -> Center
    FrontClawOpen();
    encoderDrive(10000, 14.5);
    pros::delay(500);
    encoderTurn(7500, 2.89);
    pros::delay(500);
    intakeIn(12000);
    encoderDrive(12000, 38);
    RearClawDown();
    FrontClawClose();
    intakeIn(0);
    pros::delay(500);
    encoderDrive(-12000, 45);
    pros::delay(500);
    encoderTurn(-7500, 3.5);
    pros::delay(500);
    timeDrive(-7000, 1500);
    DriveStop();
    encoderDrive(12000, 2);
    pros::delay(500);
    encoderTurn(-8000, 8);
    timeDrive(-6000,1000);
    DriveStop();
    RearClawUp();
    intakeIn(10000);
  }

  if(ProgSelect == 24){ //Left Goal Spin
    mobile_goal.set_brake_mode(MOTOR_BRAKE_HOLD);
    pros::Task my_task(my_task_fn);
    encoderDrive(12000,40);
    FrontClawClose();
    mobile_goal.move_voltage(-12000);
    encoderTurn(12000, 31);
    mobile_goal.move_voltage(0);
    pros::delay(750);
    timeDrive(12000,500);
    DriveStop();
  }

  if(ProgSelect == 25){ //CF -> Left Neutral
    FrontClawOpen();
    encoderDrive(10000, 2);
    encoderTurn4(12000, 20);
    encoderDrive(12000, 25);
    FrontClawClose();
    pros::delay(500);
    encoderTurn(10000, 1);
    pros::delay(500);
    encoderDrive(-12000, 45);
    RearClawDown();
    timeDrive(-7000, 1000);
    pros::delay(500);
    encoderDrive(12000, 2);
    pros::delay(500);
    encoderTurn(-7500, 8);
    pros::delay(500);
    timeDrive(-6000,1000);
    DriveStop();
    RearClawUp();
    pros::delay(750);
    encoderDrive(8000, 2);
    intakeIn(8000);
  }

}
