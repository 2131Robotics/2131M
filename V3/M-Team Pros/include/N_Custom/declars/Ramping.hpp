#ifndef RAMPING_HPP
#define RAMPING_HPP

class Ramping{
    public:
    int ChangePct=1;      //the amout of Pct change per loop
    int ChangeMsec=1;     //the amount of time inbetween loops

    int RequestedPct=0;   //used to request Pct value change
    int Pct=0;            //Pct output
    int MinUpPct=0;         //Used as moveing up StillSpeed
    int MinDownPct=0;       //Used as moving down StillSpeed
    int MaxPct=100;         //the max pct value

    Ramping(int CP,int CM,int MaxP=100,int MinDP=0,int MinUP=0);

    void TaskRun();

};
namespace Drive{
  void SetDRMvel(int LFpower,int LBpower,int RFpower,int RBpower); //DMR
  void DI(int Lpower,int Rpower);
  void Drive_Ramping(void*DriveRampingTask);
}
#endif /* end of include guard: RAMPING_HPP */
