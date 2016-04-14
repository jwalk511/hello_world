//#pragma config(Sensor, S4, sonarSensor, sensorSonar)
#include "boilerplate.h"


#if RUN_MAIN
task main () {
    driveStraight(1);
    turnRight(90);
    turnRight(-90);

    waitUntilStopped(motorB);
}
#endif

int getSLEncoderCount (int distance) {
   return distance * ENCODER_COUNT_PER_CM;
}

// Encoder counts for degree rotation
int getSpinEncoderCount(int degrees) {
    int ret = ((degrees * ENCODER_COUNT_PER_ROTATION) / 360);
    return ret;
}

void driveStraight(int distance) {
    resetCount(motorB);
    nSyncedTurnRatio = DRIVE_STRAIGHT;
    nMotorEncoderTarget[motorB] = getSpinEncoderCount(distance);
    motor[motorB] = 50;
    waitUntilStopped(motorB);
    wait1Msec(20);
}

void turnRight(int degrees) {
    resetCount(motorB);
    nSyncedTurnRatio = SPIN_CLOCKWISE;
    nMotorEncoderTarget[motorB] = getSLEncoderCount(degrees);
    motor[motorB] = 50 * sgn(degrees);
    waitUntilStopped(motorB);
    wait1Msec(20);
}

void resetCount (int motorNum) {
	nMotorEncoder[motorNum] = 0;
}

void waitUntilStopped (int motorNum) {
    while (nMotorRunState[motorNum] == runStateRunning){wait1Msec(20);}
}
