vex::brain Brain;

//vex::motor LeftFMotor = vex::motor(vex::PORT1);
//vex::motor RightFMotor = vex::motor(vex::PORT3, true);
vex::motor LeftBMotor = vex::motor(vex::PORT1);
vex::motor RightBMotor = vex::motor(vex::PORT6, true);
//vex::motor 


vex::motor LiftMotor = vex::motor(vex::PORT9 , true);
vex::motor WristMotor = vex::motor(vex::PORT10);
vex::motor IntakeMotor = vex::motor(vex::PORT20);
vex::motor PuncherMotor = vex::motor(vex::PORT7, true);

vex::controller Controller1 = vex::controller();