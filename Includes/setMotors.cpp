Ramping LFDR(1,5);
Ramping RFDR(1,5);
Ramping LBDR(1,5);
Ramping RBDR(1,5);

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