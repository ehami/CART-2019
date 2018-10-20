#include "main.h"

// All of the different autotnomous routines for the normal game and for robot
// skills

const char *titles[] = {"C:RD FL PF",   "C:BL FL PF",
                        "C:RD NFL PF",  "C:BL NF PF",
                        "C:RD FL NPF",  "C:BL FL NPF",
                        "C:RD NFL NPF", "C:BL NF NPF"};
void (*scripts[])() = {&chaseAuton1};

void chaseSuperAuton(bool isRed, bool nextToFlag, bool doPlatform) {
  /*
  "At 50 power 1 foot is roughly 500 milliseconds, but don't quote me on that."
       -Eric Hamilton
  */
  // bool chaseAuton = true;   // TEMP
  // bool kushalAuton = false; // TEMP
  // bool autonRed = true;  // True if robot starts on a red tile. // TEMP
  // bool autonFlag = true; // True if robot is next to a flag.// TEMP
  // bool autonPlatform = true; // True if we're going for the platform.// TEMP

  // Release actuator
  setLiftToPower(127);
  delay(200);
  setLiftToPower(-127);
  delay(200);
  setLiftToPower(0);
  // Auton 1 & 2
  if (isRed && nextToFlag) {
    // Turn left 90°
    setDriveWheelsToPower(-50, 50);
    delay(300);
    setDriveWheelsToPower(0, 0);
    // Drive forward until the robot hits the flag  ~4ft.
    setDriveWheelsToPower(50, 50);
    delay(2000);
    setDriveWheelsToPower(0, 0);
    // Drive back until aligned with cap 1  ~2ft.
    setDriveWheelsToPower(50, 50);
    delay(1000);
    setDriveWheelsToPower(0, 0);
    // Turn right 90°
    setDriveWheelsToPower(50, -50);
    delay(300);
    setDriveWheelsToPower(0, 0);
    // Drive forward until the robot grasps cap 1  ~1ft.
    setDriveWheelsToPower(50, 50);
    delay(500);
    setDriveWheelsToPower(0, 0);
    // Move the the lift all the way up
    setLiftToPower(127);
    delay(300);
    setLiftToPower(0);
    // Turn actuator 180°
    setActuatorToPower(80);
    delay(300);
    setActuatorToPower(0);
    // Turn right 90°
    setDriveWheelsToPower(50, -50);
    delay(300);
    setDriveWheelsToPower(0, 0);
    // Drive forward until next to pole 1  ~3ft.
    setDriveWheelsToPower(50, 50);
    delay(1500);
    setDriveWheelsToPower(0, 0);
    // Turn right 90°
    setDriveWheelsToPower(50, -50);
    delay(300);
    setDriveWheelsToPower(0, 0);
    // Drive forward until cap 1 is over pole 1  ~1ft.
    setDriveWheelsToPower(50, 50);
    delay(500);
    setDriveWheelsToPower(0, 0);
    // Lower lift until cap is on the pole
    setLiftToPower(-127);
    delay(300);
    setLiftToPower(0);
    // Drive back until robot has let go of cap 1  ~0.5ft.
    setDriveWheelsToPower(-50, -50);
    delay(250);
    setDriveWheelsToPower(0, 0);
    // Drive on to platform 1
    // Auton 1
    if (doPlatform == true) {
      // Turn left 90°
      setDriveWheelsToPower(-50, 50);
      delay(300);
      setDriveWheelsToPower(0, 0);
      // Drive forward until next to platform 1  ~1ft.
      setDriveWheelsToPower(50, 50);
      delay(500);
      setDriveWheelsToPower(0, 0);
      // Turn left 90°
      setDriveWheelsToPower(-50, 50);
      delay(300);
      setDriveWheelsToPower(0, 0);
      // Drive forwartd until on platform 1  ~2.5ft.
      setDriveWheelsToPower(50, 50);
      delay(750);
      setDriveWheelsToPower(0, 0);
    }
    // End of auton 1 & 2
  }
}

void kushalSuperAuton(bool isRed, bool doFlag) {
  setLiftToPower(127);
  delay(200);
  setLiftToPower(-127);
  delay(200);
  setLiftToPower(0);
  // Auton 1 & 2
  if (isRed == true && doFlag == true) {
    setDriveWheelsToPower(127, 127);
    delay(200);
    setDriveWheelsToPower(0, 0);
    setLiftToPower(127);
    delay(300);
    setLiftToPower(0);
    setActuatorToPower(127);
    delay(200);
    setActuatorToPower(0);
    setDriveWheelsToPower(127, -127);
    delay(300);
    setDriveWheelsToPower(127, 127);
    delay(200);
    setDriveWheelsToPower(127, -127);
    delay(200);
    setDriveWheelsToPower(127, 127);
    delay(100);
    setDriveWheelsToPower(127, -127);
    delay(300);
    setLiftToPower(127);
    delay(500);
    setLiftToPower(0);
    setDriveWheelsToPower(127, 127);
    delay(50);
    setDriveWheelsToPower(0, 0);
  }
}

void chaseAuton1() { chaseSuperAuton(true, true, true); }
