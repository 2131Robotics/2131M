#ifndef DRIVE_HPP
#define DRIVE_HPP

namespace Drive{
  void IsDriveFippedControll();
  void MechDriveLock();
  void MechDriveRelease();
  void ManualMechDriveCont();
  void DriveCont_LockContM();

  void Drive_Ramping(void*DriveRampingTask);
}

#endif /* end of include guard: DRIVE_HPP */
