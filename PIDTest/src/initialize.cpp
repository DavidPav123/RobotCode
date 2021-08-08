#include "main.h"
#include "MotorDefs.hpp"
#include "ScreenFunctions.hpp"

//Pre Auto variables
int Pre = 0;
double tileselect = 0;
int SideSelect = 0;
double Screen = 0;
double ProgSelect = 0;
int squareselect = 0;

void initialize() {
  center_shifter.set_value(true);
  drive_speed_shifter.set_value(false);
  pros::delay(500); //Delay to make sure it doesnt freak out
  while(Pre==0){//Gui initialize
 		if(Screen == 0){//Home Screen
 			pros::screen::erase();
      TextChanger(2);
      pros::screen::set_pen(COLOR_WHITE);
 			pros::screen::draw_rect(165,10,465,230); //Draws Main Rectangle
 			pros::screen::draw_rect(175,60,455,135); //Auto Select
 			pros::screen::draw_rect(175,145,455,220); //System Diagnostics
      pros::screen::draw_rect(410,18,455,42); //Set Box
      pros::screen::draw_line(175,50,455,50); //Underline
      pros::screen::set_pen(COLOR_MAROON);
 			pros::screen::print(TEXT_LARGE,175,15,"Home");
      pros::screen::print(TEXT_MEDIUM,225,90,"Autonomous Select");
 			pros::screen::print(TEXT_MEDIUM,220,175,"System Diagnostics");
      pros::screen::print(TEXT_MEDIUM,420,23,"Set");
      pros::delay(500);
 			while(Screen == 0){
        pros::screen_touch_status_s_t status = pros::screen::touch_status();
        if(status.touch_status > 0 ){
          if(status.y < 135 && status.y >60 && status.x < 455 && status.x > 175){
   					Screen = 2;
   				}
   				if(status.y < 220 && status.y >145 && status.x < 455 && status.x > 175){
   					Screen = 3;
   				}
          if(status.y < 42 && status.y >18 && status.x < 455 && status.x > 410){
             pros::screen::erase();
             Pre = 1;
             break;
   				}

        }
 			}
 		}
 		if(Screen == 2){ //Program Select Screen
 			pros::screen::erase();
      TextChanger(2);
 			pros::screen::set_pen(COLOR_WHITE);
 			pros::screen::draw_rect(165,10,465,230); //Draw Main Rectangle
 			pros::screen::draw_rect(175,70,310,135);
 			pros::screen::draw_rect(175,150,310,215);
      pros::screen::draw_rect(425,15,455,45);
 			pros::screen::draw_line(175,50,455,50); //Underline
      pros::screen::set_pen(COLOR_MAROON);
 			pros::screen::print(TEXT_MEDIUM,225,85,"Blue");
 			pros::screen::print(TEXT_MEDIUM,205,105,"Alliance");
 			pros::screen::print(TEXT_MEDIUM,225,165,"Red");
 			pros::screen::print(TEXT_MEDIUM,205,185,"Alliance");
 			pros::screen::print(TEXT_LARGE,175,15,"Auto");
 			pros::screen::draw_line(435,30,445,20);
 			pros::screen::draw_line(435,30,445,40);
 			pros::delay(500);
 			while(Screen == 2 ){
        pros::screen_touch_status_s_t status = pros::screen::touch_status();
        if(status.touch_status > 0 ){
 				     if(status.y < 50 && status.y >20 && status.x <455 && status.x > 425){//Exit
 					      Screen = 0;
 					      SideSelect = 0;
 				     }
 				     if(status.y < 140 && status.y >75 && status.x <310 && status.x > 175 && SideSelect != 1){ //Blue side select
     					  SideSelect = 1;
                tileselect = 0;
                autoselectBlue();
 				     }
 				     if(status.y < 220 && status.y >155 && status.x <310 && status.x > 175 && SideSelect != 2){ //Red side select
 					      SideSelect = 2;
                tileselect = 0;
                autoselectRed();
 				     }
             if(SideSelect == 1){
               if(status.y < 110 && status.y >74 && status.x <455 && status.x > 320){
                 ProgSelect = 1.1;
                 pros::screen::set_pen(COLOR_GREEN);
                 pros::screen::draw_rect(320,74,135,36);
               }
               if(status.y < 147 && status.y >110 && status.x <455 && status.x > 320){
                 ProgSelect = 1.2;
                 pros::screen::set_pen(COLOR_GREEN);
                 pros::screen::draw_rect(320,110,135,37);
               }
               if(status.y < 185 && status.y >147 && status.x <455 && status.x > 320){
                 ProgSelect = 1.3;
                 pros::screen::set_pen(COLOR_GREEN);
                 pros::screen::draw_rect(320,147,135,38);
               }
               if(status.y < 228 && status.y >185 && status.x <455 && status.x > 320){
                 ProgSelect = 1.4;
                 pros::screen::set_pen(COLOR_GREEN);
                 pros::screen::draw_rect(320,185,135,43);
               }
             }
             if(SideSelect == 2){
               if(status.y < 110 && status.y >74 && status.x <455 && status.x > 320){
                 ProgSelect = 2.1;
                 pros::screen::set_pen(COLOR_GREEN);
                 pros::screen::draw_rect(320,74,135,36);
               }
               if(status.y < 147 && status.y >110 && status.x <455 && status.x > 320){
                 ProgSelect = 2.2;
                 pros::screen::set_pen(COLOR_GREEN);
                 pros::screen::draw_rect(320,110,135,37);
               }
               if(status.y < 185 && status.y >147 && status.x <455 && status.x > 320){
                 ProgSelect = 2.3;
                 pros::screen::set_pen(COLOR_GREEN);
                 pros::screen::draw_rect(320,147,135,38);
               }
               if(status.y < 228 && status.y >185 && status.x <455 && status.x > 320){
                 ProgSelect = 2.4;
                 pros::screen::set_pen(COLOR_GREEN);
                 pros::screen::draw_rect(320,185,135,43);
               }
             }
 			  }
      }
 		}
 		if(Screen == 3){ //Settings Screen
 			while(Screen == 3){
 		}
 		}
 	}
}
