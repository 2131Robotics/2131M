#ifndef INTAKE_HPP
#define INTAKE_HPP

namespace Intake{
  extern int BottomLightValue;
  extern int TopLightValue;
  extern int BottomBallInMax;
  extern int TopBallInMax;
  extern bool BallInBottom;
  extern bool BallInTop;
  extern bool AutoIntakeOff;
  extern bool IntakeFlip;

  void Auto_Intaking(void*AutoIntaking);
}

#endif /* end of include guard: INTAKE_HPP */
