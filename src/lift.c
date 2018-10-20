#include "main.h"

//Set Lift To Power
void setLiftToPower(int power) {
    motorSet(LIFT_SHAFT_1, power);
    motorSet(LIFT_SHAFT_2, power);
}

//Set Actuator To Power
void setActuatorToPower(int power) {
    motorSet(ACTUATOR_PORT, power);
}

//Fully Raise Lift
void fullyRaiseLift() {

}

//Fully Lower Lift
void fullyLowerLift();


// gets the position (in IME ticks) of the lift
int getLiftIMEposition() {
  int ticks;
  imeGet(IME_LIFT_SHAFT, &ticks);
  return ticks;
}

// gets the position (in IME ticks) of the actuator
int getActuatorIMEposition() {
  int ticks;
  imeGet(IME_ACTUATOR, &ticks);
  return ticks;
}


void moveActuatorToValue(int degreees) {
    fbcSetGoal(&actuatorFBC, degreesToIMEticks(degreees, 627.2/*Low Speed*/));
}
