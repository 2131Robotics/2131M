#ifndef DRIVE_HPP
#define DRIVE_HPP

namespace Drive{
  void MechDriveLockA();
  void AtonDriveRamp(double Distance,int Pct=200,int EndWait=250,int Correction=0);
  void TimeAutoDrive(int time, int power);
  void AtonSlide(double Distance,int Pct=200,int EndWait=350,int Correction=2);
  void ShortSlide(double Distance,int Pct=200,int EndWait=350,int Correction=2);
  void SlideRecon(int time, int power, int dir);
  void AtonTurn(double deg,int LPowerSend=100,int RPowerSend=100,int EndWait=250);
}

#endif /* end of include guard: DRIVE_HPP */
