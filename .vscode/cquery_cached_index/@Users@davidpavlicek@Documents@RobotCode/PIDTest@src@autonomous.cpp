#include "Functions.hpp"

//Pros Task to be able to drive while also extending arms
void my_task_fn(void* param) {
  FrontClawOpen();
  ring_grabber.set_value(true);
  tilter.set_value(false);
  pros::delay(150);
  ring_grabber.set_value(false);
}

void autonomous(){
  //Blue Side Autos
  if(ProgSelect == 11){//Blue Auto 1

  }

  if(ProgSelect == 12){ //Blue Auto 2

  }

  if(ProgSelect == 13){ //Blue Auto 3

  }

  if(ProgSelect == 14){ //Blue Auto 4

  }

  if(ProgSelect == 15){ //Blue Auto 5

  }


  //Red Side Autos
  if(ProgSelect == 21){ //Red Auto 1

  }

  if(ProgSelect == 22){ //Red Auto 2

  }

  if(ProgSelect == 23){ //Red Auto 3

  }

  if(ProgSelect == 24){ //Red Auto 4

  }

  if(ProgSelect == 25){ //Red Auto 5

  }

}
