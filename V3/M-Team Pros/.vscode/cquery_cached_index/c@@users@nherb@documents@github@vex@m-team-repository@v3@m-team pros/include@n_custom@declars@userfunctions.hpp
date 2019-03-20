#ifndef USERFUNCTIONS_HPP
#define USERFUNCTIONS_HPP

namespace Drive{
  void IsDriveFippedControll();
  void MechDriveLock();
  void MechDriveRelease();
  void ManualMechDriveCont();
  void DriveCont_LockContM();
}

namespace Catapult{
  void catapultChargeFire();
}
namespace Intake{
  void intakeControll();
}
namespace Lift{
  void liftManualCont();
}
namespace Flipper{
  void FlipManualCont();
}
#endif /* end of include guard: USERFUNCTIONS_HPP */
