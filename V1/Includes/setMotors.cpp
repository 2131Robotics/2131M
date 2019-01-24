Ramping LFDR(1,8);
Ramping RFDR(1,8);
Ramping LBDR(1,8);
Ramping RBDR(1,8);

void SetDRMpower(int Lpower,int Rpower){ //DMR
    LFDR.RequestedPct = Lpower;
    RFDR.RequestedPct = -Rpower;
    LBDR.RequestedPct = -Lpower;
    RBDR.RequestedPct = Rpower;
}

//-----------------Dive Aton COntroll-----------------//
void SetDRpower(int Lpower,int Rpower){ //DR
    LDR.RequestedPct=Lpower;
    RDR.RequestedPct=Rpower;
}
/*void DI(int Lpower,int Rpower){
    LDR.RequestedPct=Lpower;
    RDR.RequestedPct=Rpower;
    LDR.Pct=Lpower;
    RDR.Pct=Rpower;
    setDrivePower(LDR.Pct,RDR.Pct);
}*/