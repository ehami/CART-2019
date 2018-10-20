// Various converters and calculators that dont really fit anywhere else

// Converts radians to degrees
double radiansToDegrees(double radians);

// Converts degrees to radians
double degreesToRadians(double degrees);
// Converts degrees to IME ticks
double degreesToIMEticks(double degrees, double ticksPerRevolution);

// Calculates gear ratio multiple (returns the inverse of the gear reduction)
// (how much to multiply the motor ticks by in order to account for gearing)).
double calculateGearRatioMultiple(int inputGearTeeth, int outputGearTeeth);
