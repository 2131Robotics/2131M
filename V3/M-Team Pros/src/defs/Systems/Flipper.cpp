#include "main.h"

namespace Flipper{ //Inside flipper namespace
  void FlipManualCont(){ //Functoin for Flipper Manual Controll
    if(!DriveDirInverted){ //If in ball mode
      if(Up.isPressed()) setFlipVel(200); //Rotate up when up is pressed
      else if(Down.isPressed()) setFlipVel(-200); //Rotate down when down is pressed
      else if(CapPush.isPressed()) FlipMotor.moveAbsolute(-240,200); //when cap flip button pressed rotoate to -240
      else setFlipVel(0); //any other time set power to 0
    }
    else{}//Do nothing in the other mode
  }
}
