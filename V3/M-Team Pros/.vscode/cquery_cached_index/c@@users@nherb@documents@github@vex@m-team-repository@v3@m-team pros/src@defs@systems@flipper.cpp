#include "main.h"

namespace Flipper{
  void FlipManualCont(){
    //Drive::IsDriveFippedControll();
    if(!DriveDirInverted){
      if(Up.isPressed()) setFlipVel(200);
      else if(Down.isPressed()) setFlipVel(-200);
      else if(CapPush.isPressed()) FlipMotor.moveAbsolute(-240,200);
      else setFlipVel(0);
    }
    else{}
  }
}
