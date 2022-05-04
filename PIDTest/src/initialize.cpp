#include "ScreenFunctions.hpp"

//Pre Auto variables
int Pre = 0;
int SideSelect = 0;
double Screen = 0;
int squareselect = 0;
int subscreen = 0;
int controllerLine = 0;
int ProgSelect = 0;

void printSelectedAuto(){ //Function for printing selected auto to the screens
	switch(ProgSelect){
		case 11:
		pros::screen::print(TEXT_LARGE,175,120,"RN+AG+Rings");
		Controller1.print(1, 8, "RN+AG+Rings");
		break;
		case 12:
		pros::screen::print(TEXT_LARGE,175,120,"Right Spin");
		Controller1.print(1, 8, "Right Spin");
		break;
		case 13:
		pros::screen::print(TEXT_LARGE,175,120,"RF->Center");
		Controller1.print(1, 8, "RF->Center");
		break;
		case 14:
		pros::screen::print(TEXT_LARGE,175,120,"CNG+AG+Rings");
		Controller1.print(1, 8, "CNG+AG+Rings");
		case 15:
		pros::screen::print(TEXT_LARGE,175,120,"CF->RN");
		Controller1.print(1, 8, "CF->RN");
		break;
		case 21:
		pros::screen::print(TEXT_LARGE,175,120,"LN+AG");
		Controller1.print(1, 8, "LN+AG");
		break;
		case 22:
		pros::screen::print(TEXT_LARGE,175,120,"CNG");
		Controller1.print(1, 8, "CNG");
		break;
		case 23:
		pros::screen::print(TEXT_LARGE,175,120,"LF->Center");
		Controller1.print(1, 8, "LF->Center");
		break;
		case 24:
		pros::screen::print(TEXT_LARGE,175,120,"Left Spin");
		Controller1.print(1, 8, "Left Spin");
		break;
		case 25:
		pros::screen::print(TEXT_LARGE,175,120,"CF->LN");
		Controller1.print(1, 8, "CF->LN");
		break;
	}
}

void initialize() {
	pros::delay(500); //Delay to make sure it doesnt freak out

	while(Pre==0){//Gui initializea
		if(Screen == 0){//Home Screen
			//Drawing the home screen
			pros::screen::erase(); //Clear screens for various reasons
			Controller1.clear(); //Clear controller screen to be able to draw text on it
			TextChanger(2); //Draws team number
			pros::screen::set_pen(COLOR_WHITE); //Pen color for outline
			pros::screen::draw_rect(165,10,465,230); //Draws Main Rectangle
			pros::screen::draw_rect(175,60,455,135); //Auto Select
			pros::screen::draw_rect(175,145,455,220); //System Diagnostics
			pros::screen::draw_rect(410,18,455,42); //Set Box
			pros::screen::draw_line(175,50,455,50); //Underline
			pros::screen::set_pen(COLOR_MAROON); //Pen color for text
			pros::screen::print(TEXT_LARGE,175,15,"Home");
			pros::screen::print(TEXT_MEDIUM,225,90,"Autonomous Select");
			pros::screen::print(TEXT_MEDIUM,220,175,"System Diagnostics");
			pros::screen::print(TEXT_MEDIUM,420,23,"Set");
			pros::delay(50); //Delay to make sure there is no accidental input
			Controller1.print(0, 5, "***SET***"); //Print on controller screen to indicate when ready to enter the Program
			pros::delay(50); //Delay to make sure there is no accidental input
			Controller1.print(1, 8, "BLUE"); //Print on controller screen to indicate when ready to enter the Program
			pros::delay(50); //Delay to make sure there is no accidental input
			Controller1.print(2, 8, "RED"); //Print on controller screen to indicate when ready to enter the Program
			pros::delay(50); //Delay to make sure there is no accidental input

			while(Screen == 0){//Home screen
				pros::screen_touch_status_s_t status = pros::screen::touch_status(); //Set up touch for brain screen
				if(status.touch_status > 0 ){
					if(status.y < 135 && status.y >60 && status.x < 455 && status.x > 175){//Program button
						Screen = 2;
					}
					if(status.y < 220 && status.y >145 && status.x < 455 && status.x > 175){//System button
						Screen = 3;
					}
					if(status.y < 42 && status.y >18 && status.x < 455 && status.x > 410){//Confirm button
						pros::screen::erase();
						Controller1.clear();
						pros::delay(150);
						printSelectedAuto();
						Pre = 1;
						break;
					}
				}
				if(Controller1.get_digital(DIGITAL_A) && controllerLine == 0){//Confirm button on controller
					pros::screen::erase();
					Controller1.clear();
					pros::delay(150);
					printSelectedAuto();
					Pre = 1;
					break;
				}

				if(Controller1.get_digital(DIGITAL_A) && controllerLine == 1){//Confirm button on controller
					pros::screen::erase();
					Controller1.clear();
					SideSelect =1;
					Screen = 2;
				}

				if(Controller1.get_digital(DIGITAL_A) && controllerLine == 2){//Confirm button on controller
					pros::screen::erase();
					Controller1.clear();
					SideSelect =2;
					Screen = 2;
				}

				if(Controller1.get_digital_new_press(DIGITAL_UP)){//Menu
					if(controllerLine == 1){
						Controller1.clear();
						pros::delay(50); //Delay to make sure there is no accidental input
						Controller1.print(0, 5, "***SET***"); //Print on controller screen to indicate when ready to enter the Program
						pros::delay(50); //Delay to make sure there is no accidental input
						Controller1.print(1, 8, "BLUE"); //Print on controller screen to indicate when ready to enter the Program
						pros::delay(50); //Delay to make sure there is no accidental input
						Controller1.print(2, 8, "RED"); //Print on controller screen to indicate when ready to enter the Program
						pros::delay(50); //Delay to make sure there is no accidental input
						controllerLine--;
					}
					else if(controllerLine == 2){
						Controller1.clear();
						pros::delay(50); //Delay to make sure there is no accidental input
						Controller1.print(0, 8, "SET"); //Print on controller screen to indicate when ready to enter the Program
						pros::delay(50); //Delay to make sure there is no accidental input
						Controller1.print(1, 4, "***BLUE***"); //Print on controller screen to indicate when ready to enter the Program
						pros::delay(50); //Delay to make sure there is no accidental input
						Controller1.print(2, 8, "RED"); //Print on controller screen to indicate when ready to enter the Program
						pros::delay(50); //Delay to make sure there is no accidental input
						controllerLine--;
					}
				}
				if(Controller1.get_digital_new_press(DIGITAL_DOWN)){//Menu
					if(controllerLine == 0){
						Controller1.clear();
						pros::delay(50); //Delay to make sure there is no accidental input
						Controller1.print(0, 8, "SET"); //Print on controller screen to indicate when ready to enter the Program
						pros::delay(50); //Delay to make sure there is no accidental input
						Controller1.print(1, 4, "***BLUE***"); //Print on controller screen to indicate when ready to enter the Program
						pros::delay(50); //Delay to make sure there is no accidental input
						Controller1.print(2, 8, "RED"); //Print on controller screen to indicate when ready to enter the Program
						pros::delay(50); //Delay to make sure there is no accidental input
						controllerLine++;
					}
					else if(controllerLine == 1){
						Controller1.clear();
						pros::delay(50); //Delay to make sure there is no accidental input
						Controller1.print(0, 8, "SET"); //Print on controller screen to indicate when ready to enter the Program
						pros::delay(50); //Delay to make sure there is no accidental input
						Controller1.print(1, 8, "BLUE"); //Print on controller screen to indicate when ready to enter the Program
						pros::delay(50); //Delay to make sure there is no accidental input
						Controller1.print(2, 4, "***RED***"); //Print on controller screen to indicate when ready to enter the Program
						pros::delay(50); //Delay to make sure there is no accidental input
						controllerLine++;
					}
				}

				pros::delay(100);
			}
		}
		if(Screen == 2){ //Program Select Screen
			pros::screen::erase();
			//Drawing program screen
			TextChanger(2); //Draw team number
			pros::screen::set_pen(COLOR_WHITE); //Pen color for outline
			pros::screen::draw_rect(165,10,465,230); //Draw Main Rectangle
			pros::screen::draw_rect(175,70,310,135);  //Blue auto Rectangle
			pros::screen::draw_rect(175,150,310,215); //Red auto Rectangle
			pros::screen::draw_rect(425,15,455,45); //Back arrow box
			pros::screen::draw_line(175,50,455,50); //Underline
			pros::screen::set_pen(COLOR_MAROON); //Pen color for text
			pros::screen::print(TEXT_MEDIUM,225,85,"Blue");
			pros::screen::print(TEXT_MEDIUM,205,105,"Alliance");
			pros::screen::print(TEXT_MEDIUM,225,165,"Red");
			pros::screen::print(TEXT_MEDIUM,205,185,"Alliance");
			pros::screen::print(TEXT_LARGE,175,15,"Auto");
			pros::screen::draw_line(435,30,445,20); //top arrow
			pros::screen::draw_line(435,30,445,40); //bottom arrow
			controllerLine = 0;
			pros::delay(50); //Delay to make sure there is no accidental input

			if(SideSelect == 1){
				Controller1.print(0, 0, "***RN+AG+Rings***"); //Print on controller screen to indicate when ready to enter the Program
				pros::delay(50); //Delay to make sure there is no accidental input
				Controller1.print(1, 5, "Right Spin"); //Print on controller screen to indicate when ready to enter the Program
				pros::delay(50); //Delay to make sure there is no accidental input
				Controller1.print(2, 5, "RF->Center"); //Print on controller screen to indicate when ready to enter the Program
				pros::delay(50); //Delay to make sure there is no accidental input
			}

			if(SideSelect == 2){
				Controller1.print(0, 5, "***LN+AG***"); //Print on controller screen to indicate when ready to enter the Program
				pros::delay(50); //Delay to make sure there is no accidental input
				Controller1.print(1, 9, "CNG"); //Print on controller screen to indicate when ready to enter the Program
				pros::delay(50); //Delay to make sure there is no accidental input
				Controller1.print(2, 5, "LF->Center"); //Print on controller screen to indicate when ready to enter the Program
				pros::delay(50); //Delay to make sure there is no accidental input
			}

			while(Screen == 2 ){
				pros::screen_touch_status_s_t status = pros::screen::touch_status();
				if(status.touch_status > 0 ){
					if(status.y < 50 && status.y >20 && status.x <455 && status.x > 425){//Exit
						Screen = 0;
						SideSelect = 0;
					}
					if(status.y < 140 && status.y >75 && status.x <310 && status.x > 175 && SideSelect != 1){ //Blue side select
						SideSelect = 1;
						autoselectBlue();
					}
					if(status.y < 220 && status.y >155 && status.x <310 && status.x > 175 && SideSelect != 2){ //Red side select
						SideSelect = 2;
						autoselectRed();
					}
					if(SideSelect == 1){ //If statments for selecting blue side autos
						autoselectBlue();
						pros::screen::set_pen(COLOR_GREEN);
						if(status.y < 92 && status.y >60 && status.x <455 && status.x > 320){
							ProgSelect = 11;
							pros::screen::draw_rect(320,60,455,92);
						}
						if(status.y < 124 && status.y >92 && status.x <455 && status.x > 320){
							ProgSelect = 12;
							pros::screen::draw_rect(320,92,455,124);
						}
						if(status.y < 156 && status.y >124 && status.x <455 && status.x > 320){
							ProgSelect = 13;
							pros::screen::draw_rect(320,124,455,156);
						}
						if(status.y < 188 && status.y >156 && status.x <455 && status.x > 320){
							ProgSelect = 14;
							pros::screen::draw_rect(320,156,455,188);
						}
						if(status.y < 220 && status.y >188 && status.x <455 && status.x > 320){
							ProgSelect = 15;
							pros::screen::draw_rect(320,188,455,220);
						}
					}
					if(SideSelect == 2){ //If statments for selecting red side autos
						autoselectRed();
						pros::screen::set_pen(COLOR_GREEN);
						if(status.y < 92 && status.y >60 && status.x <455 && status.x > 320){
							ProgSelect = 21;
							pros::screen::draw_rect(320,60,455,92);
						}
						if(status.y < 124 && status.y >92 && status.x <455 && status.x > 320){
							ProgSelect = 22;
							pros::screen::draw_rect(320,92,455,124);
						}
						if(status.y < 156 && status.y >124 && status.x <455 && status.x > 320){
							ProgSelect = 23;
							pros::screen::draw_rect(320,124,455,156);
						}
						if(status.y < 188 && status.y >156 && status.x <455 && status.x > 320){
							ProgSelect = 24;
							pros::screen::draw_rect(320,156,455,188);
						}
						if(status.y < 220 && status.y >188 && status.x <455 && status.x > 320){
							ProgSelect = 25;
							pros::screen::draw_rect(320,188,455,220);
						}
					}
				}
				pros::delay(100); //Delay to save resources
			}
		}
		if(Screen == 3){ //Settings Screen
			pros::screen::erase();
			TextChanger(2); //Draw Team number
			pros::screen::set_pen(COLOR_WHITE); //Pen color for outline
			pros::screen::draw_rect(165,10,465,230); //Draw Main Rectangle
			pros::screen::draw_rect(425,15,455,45); //Back arrow square
			pros::screen::draw_line(175,50,455,50); //Underline
			pros::screen::set_pen(COLOR_MAROON); //Pen color for text
			pros::screen::print(TEXT_LARGE,175,15,"System");
			pros::screen::draw_line(435,30,445,20); //top arrow
			pros::screen::draw_line(435,30,445,40); //bottom arrow
			if(subscreen == 0){
				MotorConnected();
			}else if(subscreen == 1){
				SensorConnected();
			}
			pros::delay(1000);
			while(Screen == 3){
				pros::screen_touch_status_s_t status = pros::screen::touch_status();
				if(status.touch_status > 0 ){
					if(status.y < 50 && status.y >20 && status.x <455 && status.x > 425){//Exit
						Screen = 0;
					}
					if(status.y < 105 && status.y >75 && status.x <455 && status.x > 425){//Page change
						if(subscreen == 0){
							subscreen = 1;
							Screen = 4;
						}else if(subscreen == 1){
							subscreen = 0;
							Screen = 4;
						}
					}
				} //End of touch
				if(subscreen == 0){
					MIfChain();
				}
				if(subscreen == 1){
					SensorChain();
				}
				pros::delay(100); //Delay to save resources
			}
		}
		if(Screen == 4){//Reset screen 3
			Screen = 3;
		}

	}
}
