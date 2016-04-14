#ifndef boilerplate
#define boilerplate
//#include "init.h"
#define MOTOR_A_POWER 17

#define RUN_MAIN 0

//Use with
#define DRIVE_STRAIGHT +100
#define SPIN_CLOCKWISE -100

#define ENCODER_COUNT_PER_ROTATION 1945

//Ticks per Rotation(motor) * (Rotations(motor) / rotations(wheel)) * (Rotations(wheel) / Circumference)
//= Ticks / Distance Travelled
//Best experimental guess = 2000
#define ENCODER_COUNT_PER_CM (360 * 40 / (24 * 100 * 0.255))
//we still need to figure this out

//reset tick count to 0
void resetCount (int motorNum);

//wait until motor has finished moving.
//Use with nMotorEncoderTarget
void waitUntilStopped(int motorNum);

int getSLEncoderCount (int distance);

void driveStraight(int distance);

int getSpinEncoderCount(int degrees);

void turnRight(int degrees);

#endif
