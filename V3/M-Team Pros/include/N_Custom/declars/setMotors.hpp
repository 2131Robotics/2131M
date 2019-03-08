#ifndef SETMOTORS_HPP
#define SETMOTORS_HPP

void setMechLFPower(int pct);
void setMechLBPower(int pct);
void setMechRFPower(int pct);
void setMechRBPower(int pct);

void setMechDrivePower(int LF,int LB,int RF,int RB);
void DriveMechPowerSend(int j1,int j2,int j3,int j4);
void setDrivePower(int left, int right);

void setIntakePower(int vel);
void setFlipPower(int vel);
void setCatapultPower(int vel);
void setLiftPower(int vel);

#endif /* end of include guard: SETMOTORS_HPP */
