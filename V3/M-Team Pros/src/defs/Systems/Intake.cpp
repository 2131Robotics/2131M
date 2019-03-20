#include "main.h"

namespace Intake{
  void intakeControll(){
    //Drive::IsDriveFippedControll();
    if(!DriveDirInverted){
        if(In.isPressed()) setIntakeVel(600);
        else if(Out.isPressed()) setIntakeVel(-600);
        else setIntakeVel(0);
      }
    else{}
  }
}
