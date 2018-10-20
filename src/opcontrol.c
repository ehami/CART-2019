/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any
 * functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user operator control code. This function will be started in its own
 * task with the default priority and stack size whenever the robot is enabled
 * via the Field Management System or the VEX Competition Switch in the operator
 * control mode. If the robot is disabled or communications is lost, the
 * operator control task will be stopped by the kernel. Re-enabling the robot
 * will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the
 * VEX Cortex will run the operator control task. Be warned that this will also
 * occur if the VEX Cortex is tethered directly to a computer via the USB A to A
 * cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is
 * available and the scheduler is operational. However, proper use of delay() or
 * taskDelayUntil() is highly recommended to give other tasks (including system
 * tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop,
 * even if empty.
 */
void operatorControl() {
  int power = 0;
  int turn = 0;
  while (true) {

    // Wheels
    power = joystickGetAnalog(1, 3) * 0.65; // vertical axis on right joystick
    turn = joystickGetAnalog(1, 1) * 0.8;   // horizontal axis on right joystick
    // printf("Power: %d, Turn: %d\n", power, turn);

    if (abs(power) > 10 || abs(turn) > 10) {
      setDriveWheelsToPower(power + turn, power - turn);
    } else {
      setDriveWheelsToPower(0, 0);
    }

    // Lift
    if (joystickGetDigital(1, 5, JOY_UP)) {
      setLiftToPower(90);
    } else if (joystickGetDigital(1, 5, JOY_DOWN)) {
      setLiftToPower(-90);
    } else {
      setLiftToPower(0);
    }

    /*if (joystickGetDigital(1, 8, JOY_UP)) {
      setActuatorToPower(127);
    } else if (joystickGetDigital(1, 8, JOY_DOWN)) {
      setActuatorToPower(-127);
    } else {
      setActuatorToPower(0);
  }*/

    if (joystickGetDigital(1, 8, JOY_LEFT)) {
      // moveActuatorToValue(180 * 3);
      fbcSetGoal(&actuatorFBC, 627.2 * 180/360 * 60/12);
      //setActuatorToPower(fbcGenerateOutput(&actuatorFBC));

    } else if (joystickGetDigital(1, 8, JOY_RIGHT)) {
      // moveActuatorToValue(0);
      fbcSetGoal(&actuatorFBC, 0);
      //setActuatorToPower(fbcGenerateOutput(&actuatorFBC));
    }
    setActuatorToPower(fbcGenerateOutput(&actuatorFBC));

    lcdPrint(uart1, 2, "%d %d", getActuatorIMEposition(),
             fbcGenerateOutput(&actuatorFBC));
    delay(20);
  }
}
