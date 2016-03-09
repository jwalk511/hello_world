#pragma config(Sensor, S4, sonarSensor, sensorSonar)
#include "boilerplate.h"


void resetCount (int motorNum) {
	nMotorEncoder[motorNum] = 0;
}

void waitUntilStopped (int motorNum) {
	while (nMotorRunState[motorNum] == runStateRunning){};
}
int getSLEncoderCount (int distance);

task main () {
    nSyncedMotors = synchBC;
    nSyncedTurnRatio = DRIVE_STRAIGHT;
    nMotorEncoderTarget[motorB] = getSLEncoderCount(30);
    motor[motorB] = 50;
    
    waitUntilMotorStop(motorB);
}
    
int getSLEncoderCount (int distance) {
    return ENCODER_COUNT_PER_CM;
}