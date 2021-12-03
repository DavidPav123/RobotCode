#include "main.h"
#include "ScreenFunctions.hpp"

//Pre Auto variables
int Pre = 0;
double tileselect = 0;
int SideSelect = 0;
double Screen = 0;
int squareselect = 0;
int subscreen = 0;
int contollerLine = 0;


void initialize() {
  pros::delay(500); //Delay to make sure it doesnt freak out
  while(Pre==0){//Gui initializea
 		if(Screen == 0){//Home Screen
 			pros::screen::erase();
      Controller1.clear();
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
      //Controller screen
      pros::delay(500); //Delay to make sure there is no accidental input
      Controller1.print(0, 8, "Set");
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
             Controller1.clear();
             pros::delay(150);
             printSelectedAuto();
             Pre = 1;
             break;
   				}
        }
        if(Controller1.get_digital(DIGITAL_A) && contollerLine == 0){
          pros::screen::erase();
          Controller1.clear();
          pros::delay(150);
          printSelectedAuto();
          Pre = 1;
          break;
        }
        pros::delay(100);
 			}
    }
 		if(Screen == 2){ //Program Select Screen
 			pros::screen::erase();
      TextChanger(2);
 			pros::screen::set_pen(COLOR_WHITE);
 			pros::screen::draw_rect(165,10,465,230); //Draw Main Rectangle
 			pros::screen::draw_rect(175,70,310,135);  //Blue auto Rectangle
 			pros::screen::draw_rect(175,150,310,215); //Red auto Rectangle
      pros::screen::draw_rect(425,15,455,45); //Back arrow box
 			pros::screen::draw_line(175,50,455,50); //Underline
      pros::screen::set_pen(COLOR_MAROON);
 			pros::screen::print(TEXT_MEDIUM,225,85,"Blue");
 			pros::screen::print(TEXT_MEDIUM,205,105,"Alliance");
 			pros::screen::print(TEXT_MEDIUM,225,165,"Red");
 			pros::screen::print(TEXT_MEDIUM,205,185,"Alliance");
 			pros::screen::print(TEXT_LARGE,175,15,"Auto");
      pros::screen::draw_line(435,30,445,20); //top arrow
 			pros::screen::draw_line(435,30,445,40); //bottom arrow
 			pros::delay(500); //Delay to make sure there is no accidental input
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
               autoselectBlue();
               pros::screen::set_pen(COLOR_GREEN);
               if(status.y < 110 && status.y >74 && status.x <455 && status.x > 320){
                 ProgSelect = 11;
                 pros::screen::draw_rect(320,69,455,105);
               }
               if(status.y < 147 && status.y >110 && status.x <455 && status.x > 320){
                 ProgSelect = 12;
                 pros::screen::draw_rect(320,105,455,142);
               }
               if(status.y < 185 && status.y >147 && status.x <455 && status.x > 320){
                 ProgSelect = 13;
                 pros::screen::draw_rect(320,142,455,179);
               }
               if(status.y < 228 && status.y >185 && status.x <455 && status.x > 320){
                 ProgSelect = 14;
                 pros::screen::draw_rect(320,179,455,216);
               }
             }
             if(SideSelect == 2){
               autoselectRed();
               pros::screen::set_pen(COLOR_GREEN);
               if(status.y < 110 && status.y >74 && status.x <455 && status.x > 320){
                 ProgSelect = 21;
                 pros::screen::draw_rect(320,69,455,105);
               }
               if(status.y < 147 && status.y >110 && status.x <455 && status.x > 320){
                 ProgSelect = 22;
                 pros::screen::draw_rect(320,105,455,142);
               }
               if(status.y < 185 && status.y >147 && status.x <455 && status.x > 320){
                 ProgSelect = 23;
                 pros::screen::draw_rect(320,142,455,179);
               }
               if(status.y < 228 && status.y >185 && status.x <455 && status.x > 320){
                 ProgSelect = 24;
                 pros::screen::draw_rect(320,179,455,216);
               }
             }
 			  }
        pros::delay(100); //Delay to save resources
      }
 		}
 		if(Screen == 3){ //Settings Screen
      pros::screen::erase();
      TextChanger(2);
 			pros::screen::set_pen(COLOR_WHITE);
 			pros::screen::draw_rect(165,10,465,230); //Draw Main Rectangle
      pros::screen::draw_rect(425,15,455,45); //Back arrow square
 			pros::screen::draw_line(175,50,455,50); //Underline
      pros::screen::set_pen(COLOR_MAROON);
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
