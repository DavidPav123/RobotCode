#include "main.h"

void autoselectRed(){
	pros::screen::set_pen(COLOR_RED);
  pros::screen::draw_rect(320,69,455,216);
  pros::screen::draw_line(320,105,455,105);
  pros::screen::draw_line(320,142,455,142);
  pros::screen::draw_line(320,179,455,179);
  pros::screen::print(TEXT_MEDIUM,328,80,"Placeholder 1");
  pros::screen::print(TEXT_MEDIUM,328,118,"Placeholder 2");
  pros::screen::print(TEXT_MEDIUM,328,156,"Placeholder 3");
  pros::screen::print(TEXT_MEDIUM,328,193,"Placeholder 4");
}
void autoselectBlue(){
  pros::screen::set_pen(COLOR_BLUE);
  pros::screen::draw_rect(320,69,455,216);
  pros::screen::draw_line(320,105,455,105);
  pros::screen::draw_line(320,142,455,142);
  pros::screen::draw_line(320,179,455,179);
  pros::screen::print(TEXT_MEDIUM,328,80,"Placeholder 1");
  pros::screen::print(TEXT_MEDIUM,328,118,"Placeholder 2");
  pros::screen::print(TEXT_MEDIUM,328,156,"Placeholder 3");
  pros::screen::print(TEXT_MEDIUM,328,193,"Placeholder 4");
}

void TextChanger(int pencolour){
	if(pencolour == 0){
		pros::screen::set_pen(COLOR_SILVER);
	}
	if(pencolour == 1){
		pros::screen::set_pen(COLOR_BLUE);
	}
	if(pencolour == 2){
		pros::screen::set_pen(COLOR_GOLD);
	}
  //4
	pros::screen::draw_line(40,10,70,10);
	pros::screen::draw_line(10,35,10,65);
	pros::screen::draw_line(40,10,10,35);
	pros::screen::draw_line(10,65,40,65);
	pros::screen::draw_line(70,10,70,45);
	pros::screen::draw_line(20,65,40,65);
	pros::screen::draw_line(70,45,85,45);
	pros::screen::draw_line(85,45,85,65);
	pros::screen::draw_line(65,65,85,65);
	pros::screen::draw_line(65,65,65,85);
	pros::screen::draw_line(40,65,40,85);
	pros::screen::draw_line(40,85,65,85);
	pros::screen::draw_line(50,30,50,50);
	pros::screen::draw_line(30,50,50,50);
	pros::screen::draw_line(30,49,49,29);
  //4
	pros::screen::draw_line(110,60,140,60);
	pros::screen::draw_line(80,85,80,115);
	pros::screen::draw_line(110,60,80,85);
	pros::screen::draw_line(80,115,110,115);
	pros::screen::draw_line(140,60,140,95);
	pros::screen::draw_line(90,115,110,115);
	pros::screen::draw_line(140,95,155,95);
	pros::screen::draw_line(155,95,155,115);
	pros::screen::draw_line(135,115,155,115);
	pros::screen::draw_line(135,115,135,135);
	pros::screen::draw_line(110,115,110,135);
	pros::screen::draw_line(110,135,135,135);
	pros::screen::draw_line(120,80,120,100);
	pros::screen::draw_line(100,100,120,100);
	pros::screen::draw_line(100,99,119,79);
  //4
	pros::screen::draw_line(40,110,70,110);
	pros::screen::draw_line(10,135,10,165);
	pros::screen::draw_line(40,110,10,135);
	pros::screen::draw_line(10,165,40,165);
	pros::screen::draw_line(70,110,70,145);
	pros::screen::draw_line(20,165,40,165);
	pros::screen::draw_line(70,145,85,145);
	pros::screen::draw_line(85,145,85,165);
	pros::screen::draw_line(65,165,85,165);
	pros::screen::draw_line(65,165,65,185);
	pros::screen::draw_line(40,165,40,185);
	pros::screen::draw_line(40,185,65,185);
	pros::screen::draw_line(50,130,50,150);
	pros::screen::draw_line(30,150,50,150);
	pros::screen::draw_line(30,149,49,129);
  //2
	pros::screen::draw_line(105,160,135,160);
	pros::screen::draw_line(90,170,90,185);
	pros::screen::draw_line(105,160,90,170);
	pros::screen::draw_line(135,160,150,170);
	pros::screen::draw_line(150,170,150,190);
	pros::screen::draw_line(90,235,150,235);
	pros::screen::draw_line(90,220,90,235);
	pros::screen::draw_line(150,220,150,235);
	pros::screen::draw_line(120,220,150,220);
	pros::screen::draw_line(120,220,149,190);
	pros::screen::draw_line(90,185,110,185);
	pros::screen::draw_line(110,175,110,185);
	pros::screen::draw_line(110,175,125,175);
	pros::screen::draw_line(125,175,125,185);
	pros::screen::draw_line(125,185,90,220);
}

void MotorConnected(){
	pros::screen::set_pen(COLOR_WHITE);
	pros::screen::draw_line(165,110,465,110); //Top line
	pros::screen::draw_line(165,140,465,140); //2nd line
	pros::screen::draw_line(165,170,465,170); //3rd line
	pros::screen::draw_line(165,200,465,200); //4th line
	pros::screen::draw_line(315,110,315,230); //Verticle line
	pros::screen::draw_rect(425,75,455,105); //Next page arrow square
	pros::screen::set_pen(COLOR_MAROON);
	pros::screen::print(TEXT_MEDIUM,170,90,"MOTORS");
	pros::screen::draw_line(445,90,435,80); //Top arrow
	pros::screen::draw_line(445,90,435,100); //Bottom arrow
	pros::screen::print(TEXT_SMALL,170,120,"19:Left Front"); //Left 1
	pros::screen::print(TEXT_SMALL,170,150,"17:Center Left"); //Left 2
	pros::screen::print(TEXT_SMALL,170,180,"20:Left Back"); //Left 3
	pros::screen::print(TEXT_SMALL,170,210,"13:Ring Four Bar"); //Left 4
	pros::screen::print(TEXT_SMALL,320,120,"11:Right Front"); //Right 1
	pros::screen::print(TEXT_SMALL,320,150,"18:Center Right"); //Right 2
	pros::screen::print(TEXT_SMALL,320,180,"12:Right Back"); //Right 3
	pros::screen::print(TEXT_SMALL,320,210,"14:Mobile Goal"); //Right 4
	pros::screen::set_pen(COLOR_RED);
	//Create status circles
	pros::screen::fill_circle(305, 125, 5);
	pros::screen::fill_circle(305, 155, 5);
	pros::screen::fill_circle(305, 185, 5);
	pros::screen::fill_circle(305, 215, 5);
	pros::screen::fill_circle(455, 125, 5);
	pros::screen::fill_circle(455, 155, 5);
	pros::screen::fill_circle(455, 185, 5);
	pros::screen::fill_circle(455, 215, 5);
}

void SensorConnected(){
	pros::screen::set_pen(COLOR_WHITE);
	pros::screen::draw_line(165,110,465,110); //Top line
	pros::screen::draw_line(165,140,465,140); //2nd line
	pros::screen::draw_line(165,170,465,170); //3rd line
	pros::screen::draw_line(165,200,465,200); //4th line
	pros::screen::draw_line(315,110,315,230); //Verticle line
	pros::screen::draw_rect(425,75,455,105); //First page arrow square
	pros::screen::set_pen(COLOR_MAROON);
	pros::screen::print(TEXT_MEDIUM,170,90,"Sensors");
	pros::screen::draw_line(445,80,435,90); //Top arrow
	pros::screen::draw_line(445,100,435,90); //Bottom arrow
	pros::screen::print(TEXT_SMALL,170,120,"6:Left roto"); //Left 1
	pros::screen::print(TEXT_SMALL,170,150,"A:Mobo pot"); //Left 2
	pros::screen::print(TEXT_SMALL,320,120,"15:Right roto"); //Right 1
	pros::screen::print(TEXT_SMALL,320,150,"E:Ringly pot"); //Right 2
	pros::screen::set_pen(COLOR_RED);
	//Create status circles
	pros::screen::fill_circle(305, 125, 5);
	pros::screen::fill_circle(305, 155, 5);
	//pros::screen::fill_circle(305, 185, 5);
	//pros::screen::fill_circle(305, 215, 5);
	pros::screen::fill_circle(455, 125, 5);
	pros::screen::fill_circle(455, 155, 5);
	//pros::screen::fill_circle(455, 185, 5);
	//pros::screen::fill_circle(455, 215, 5);
}

void MIfChain(){
	if(left_back_motor.get_temperature() < 50){
		pros::screen::set_pen(COLOR_GREEN);
		pros::screen::fill_circle(305, 185, 5);
	}
	else if(left_back_motor.get_temperature() < 100){
		pros::screen::set_pen(COLOR_YELLOW);
		pros::screen::fill_circle(305, 185, 5);
	}
	else{
		pros::screen::set_pen(COLOR_RED);
		pros::screen::fill_circle(305, 185, 5);
	}
	if(left_front_motor.get_temperature() < 50){
		pros::screen::set_pen(COLOR_GREEN);
		pros::screen::fill_circle(305, 125, 5);
	}
	else if(left_front_motor.get_temperature() < 100){
		pros::screen::set_pen(COLOR_YELLOW);
		pros::screen::fill_circle(305, 125, 5);
	}
	else{
		pros::screen::set_pen(COLOR_RED);
		pros::screen::fill_circle(305, 125, 5);
	}
	if(center_left.get_temperature() < 50){
		pros::screen::set_pen(COLOR_GREEN);
		pros::screen::fill_circle(305, 155, 5);
	}
	else if(center_left.get_temperature() < 100){
		pros::screen::set_pen(COLOR_YELLOW);
		pros::screen::fill_circle(305, 155, 5);
	}
	else{
		pros::screen::set_pen(COLOR_RED);
		pros::screen::fill_circle(305, 155, 5);
	}
	if(right_front_motor.get_temperature() < 50){
		pros::screen::set_pen(COLOR_GREEN);
		pros::screen::fill_circle(455, 125, 5);
	}
	else if(right_front_motor.get_temperature() < 100){
		pros::screen::set_pen(COLOR_YELLOW);
		pros::screen::fill_circle(455, 125, 5);
	}
	else{
		pros::screen::set_pen(COLOR_RED);
		pros::screen::fill_circle(455, 125, 5);
	}
	if(right_back_motor.get_temperature() < 50){
		pros::screen::set_pen(COLOR_GREEN);
		pros::screen::fill_circle(455, 185, 5);
	}
	else if(right_back_motor.get_temperature() < 100){
		pros::screen::set_pen(COLOR_YELLOW);
		pros::screen::fill_circle(455, 185, 5);
	}
	else{
		pros::screen::set_pen(COLOR_RED);
		pros::screen::fill_circle(455, 185, 5);
	}
	if(center_right.get_temperature() < 50){
		pros::screen::set_pen(COLOR_GREEN);
		pros::screen::fill_circle(455, 155, 5);
	}
	else if(center_right.get_temperature() < 100){
		pros::screen::set_pen(COLOR_YELLOW);
		pros::screen::fill_circle(455, 155, 5);
	}
	else{
		pros::screen::set_pen(COLOR_RED);
		pros::screen::fill_circle(455, 155, 5);
	}
	if(ringly_dingler.get_temperature() < 50){
		pros::screen::set_pen(COLOR_GREEN);
		pros::screen::fill_circle(305, 215, 5);
	}
	else if(ringly_dingler.get_temperature() < 100){
		pros::screen::set_pen(COLOR_YELLOW);
		pros::screen::fill_circle(305, 215, 5);
	}
	else{
		pros::screen::set_pen(COLOR_RED);
		pros::screen::fill_circle(305, 215, 5);
	}
	if(mobile_goal.get_temperature() < 50){
		pros::screen::set_pen(COLOR_GREEN);
		pros::screen::fill_circle(455, 215, 5);
	}
	else if(mobile_goal.get_temperature() < 100){
		pros::screen::set_pen(COLOR_YELLOW);
		pros::screen::fill_circle(455, 215, 5);
	}
	else{
		pros::screen::set_pen(COLOR_RED);
		pros::screen::fill_circle(455, 215, 5);
	}
}

void SensorChain(){
	if(rotation_left.get_velocity()> 2000000000){
		pros::screen::set_pen(COLOR_RED);
		pros::screen::fill_circle(305, 125, 5);
	}
	else{
		pros::screen::set_pen(COLOR_GREEN);
		pros::screen::fill_circle(305, 125, 5);
	}
	if(rotation_right.get_velocity()> 2000000000){
		pros::screen::set_pen(COLOR_RED);
		pros::screen::fill_circle(455, 125, 5);
	}
	else{
		pros::screen::set_pen(COLOR_GREEN);
		pros::screen::fill_circle(455, 125, 5);
	}
	if(mobo_pot.get_value() == 39){
		pros::screen::set_pen(COLOR_RED);
		pros::screen::fill_circle(305, 155, 5);
	}
	else{
		pros::screen::set_pen(COLOR_GREEN);
		pros::screen::fill_circle(305, 155, 5);
	}
	if(ring_pot.get_value() == 40 || ring_pot.get_value() == 10){
		pros::screen::set_pen(COLOR_RED);
		pros::screen::fill_circle(455, 155, 5);
	}
	else{
		pros::screen::set_pen(COLOR_GREEN);
		pros::screen::fill_circle(455, 155, 5);
	}
}
