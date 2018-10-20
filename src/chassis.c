#include "main.h"

// Sets the left and right motors to the specifified values
void setDriveWheelsToPower(int left, int right) {
  setLeftWheelsToPower(left);
  setRightWheelsToPower(-right);
}

// Sets the left motors to a specific power level. (positive values go forward)
void setLeftWheelsToPower(int power) {
  // blrsMotorSet(LEFT_MOTOR_PORT, power, true);
  motorSet(LEFT_MOTOR_PORT, power);
}

// Sets the right motors to a specific power level. (positive values go
// backward)
void setRightWheelsToPower(int power) {
  // blrsMotorSet(RIGHT_MOTOR_PORT, power, true);
  motorSet(RIGHT_MOTOR_PORT, power);
}
