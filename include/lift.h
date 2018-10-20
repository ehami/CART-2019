//Set Lift To Power
void setLiftToPower(int power);

//Set Actuator To Power
void setActuatorToPower(int power);

//Fully Raise Lift
void fullyRaiseLift();

//Fully Lower Lift
void fullyLowerLift();

// gets the position (in IME ticks) of the lift
int getLiftIMEposition();

// gets the position (in IME ticks) of the actuator
int getActuatorIMEposition();

void moveActuatorToValue(int degreees);
