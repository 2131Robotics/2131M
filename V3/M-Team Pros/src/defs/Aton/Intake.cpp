#include "main.h"
#include "N_Custom/declars/Aton/Intake.hpp"

namespace Intake{

  int	BottomLightValue;
  int TopLightValue;
  int BottomBallInMax = 2500;
  int TopBallInMax = 2500;

  bool BallInBottom;
  bool BallInTop;

  bool AutoIntakeOff = false;
  bool IntakeFlip=false;

  void Auto_Intaking(void*AutoIntaking){
    AutoIntakeTaskEnabled = true;
    while(AutoIntakeTaskEnabled){
      BottomLightValue = BallSenseBottom.get_value();
      TopLightValue = BallSenseTop.get_value();

      if (BottomLightValue < BottomBallInMax) BallInBottom = true;
      else BallInBottom = false;

      if (TopLightValue < TopBallInMax) BallInTop = true;
      else BallInTop = false;

      if(AutoIntakeOff){
        setIntakeVel(0);
        if(IntakeFlip) setIntakeVel(-600);
      }
      else if(BallInBottom && BallInTop) setIntakeVel(-10);
      else setIntakeVel(600);
    }
    setIntakeVel(0);
  }
}
