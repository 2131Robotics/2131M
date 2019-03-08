class Ramping{
    public:
    int ChangePct=1;      //the amout of Pct change per loop
    int ChangeMsec=1;     //the amount of time inbetween loops

    int RequestedPct=0;   //used to request Pct value change
    int Pct=0;            //Pct output
    int MinUpPct=0;         //Used as moveing up StillSpeed
    int MinDownPct=0;       //Used as moving down StillSpeed
    int MaxPct=100;         //the max pct value

    Ramping(); //object specifer

    Ramping(int CP,int CM,int MaxP=100,int MinDP=0,int MinUP=0){
        //ChangePct,ChangeMsec,MaxPct
        ChangePct=CP;
        ChangeMsec=CM;
        MaxPct=MaxP;
        MinUpPct=MinUP;
        MinDownPct=MinDP;
    }

    void TaskRun(){
        if(RequestedPct>Pct){ //ramp up
            Pct=Pct+ChangePct;
        }
        else if(RequestedPct<Pct){ //ramp down
            Pct=Pct-ChangePct;
        }
        //limit Pct
        if(Pct>MaxPct)	Pct=MaxPct;
        if(Pct<-MaxPct)	Pct=-MaxPct;
        if(Pct>0 && Pct<MinUpPct) Pct=MinUpPct;
        if(Pct<0 && Pct>MinDownPct)    Pct=MinDownPct;
    }
};

Ramping LFDR(1,6);
Ramping RFDR(1,6);
Ramping LBDR(1,6);
Ramping RBDR(1,6);

void SetDRMpower(int LFpower,int LBpower,int RFpower,int RBpower){ //DMR
    LFDR.RequestedPct = LFpower;
    RFDR.RequestedPct = RFpower;
    LBDR.RequestedPct = LBpower;
    RBDR.RequestedPct = RBpower;
}
void DI(int Lpower,int Rpower){
    LFDR.RequestedPct=Lpower;
    RFDR.RequestedPct=Rpower;
    LBDR.RequestedPct=Lpower;
    RBDR.RequestedPct=Rpower;
    LFDR.Pct=Lpower;
    RFDR.Pct=Rpower;
    LBDR.Pct=Lpower;
    RBDR.Pct=Rpower;
    setDrivePower(LBDR.Pct,RBDR.Pct);
}