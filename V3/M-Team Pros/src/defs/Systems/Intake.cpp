#include "main.h"

namespace Intake{ //inside intake namespace
  void intakeControll(){ //Function that runs intake controll
    if(!DriveDirInverted){ //In abll mode
        if(In.isPressed()) setIntakeVel(600);
        else if(Out.isPressed()) setIntakeVel(-600);
        else setIntakeVel(0);
      }
    else{} // Run nothing in lift mode
  }
}
