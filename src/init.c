/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions
 * related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs pre-initialization code. This function will be started in kernel mode
 * one time while the VEX Cortex is starting up. As the scheduler is still
 * paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes
 * (pinMode()) and port states (digitalWrite()) of limit switches, push buttons,
 * and solenoids. It can also safely configure a UART port (usartOpen()) but
 * cannot set up an LCD (lcdInit()).
 */
void initializeIO() {}

/*
 * Runs user initialization code. This function will be started in its own task
 * with the default priority and stack size once when the robot is starting up.
 * It is possible that the VEXnet communication link may not be fully
 * established at this time, so reading from the VEX Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics),
 * LCDs, global variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and
 * autonomous() tasks will not start. An autonomous mode selection menu like the
 * pre_auton() in other environments can be implemented in this task if desired.
 */
void initialize() {
  setTeamName("CART9498");

  lcdScriptInit(uart1);
  print("Init Started");

  // Inititialize IMEs
  int IMECount = imeInitializeAll();
  // Ensure all IMEs are plugged in
  if (IMECount != NUMBER_OF_IME) {
    printf("ALL IMEs ARE NOT CONNECTED. There are only %d of %d connected.\n",
           IMECount, NUMBER_OF_IME);
    lcdPrint(uart1, 2, "%d/%d IMEs connected", IMECount, NUMBER_OF_IME);
  }

  // Lift PID Controller
  imeReset(IME_LIFT_SHAFT); // Reset the IME on startup
  fbcPIDInitializeData(/*PID controller*/ &liftPID,
                       /*P*/ 0.1,
                       /*I*/ 0.01,
                       /*D*/ 0,
                       /*minI*/ 0,
                       /*minI*/ 0);
  fbcInit(/*FBC controller*/ &liftFBC,
          /*move*/ setLiftToPower,
          /*sensor*/ getLiftIMEposition,
          /*reset function pointer (not used, so null)*/ NULL,
          /*stall detect (using default)*/ fbcStallDetect,
          /*neg_deadband*/ -15,
          /*pos_deadband*/ 15,
          /*acceptableTolerance*/ 10,
          /*acceptableConfidence*/ 5);
  fbcPIDInit(/*FBC controller*/ &liftFBC,
             /*PID controller*/ &liftPID);

  // Actuator PID Controller
  imeReset(IME_ACTUATOR); // Reset the IME on startup
  fbcPIDInitializeData(/*PID controller*/ &actuatorPID,
                       /*P*/ 0.1,
                       /*I*/ 0.01,
                       /*D*/ 0,
                       /*minI*/ 0,
                       /*minI*/ 0);
  fbcInit(/*FBC controller*/ &actuatorFBC,
          /*move*/ setActuatorToPower,
          /*sensor*/ getActuatorIMEposition,
          /*reset function pointer (not used, so null)*/ NULL,
          /*stall detect (using default)*/ fbcStallDetect,
          /*neg_deadband*/ -22,
          /*pos_deadband*/ 22,
          /*acceptableTolerance*/ 10,
          /*acceptableConfidence*/ 5);
  fbcPIDInit(/*FBC controller*/ &actuatorFBC,
             /*PID controller*/ &actuatorPID);

  lcdScriptSelect();
}
