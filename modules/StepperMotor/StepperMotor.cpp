#include "StepperMotor.h"
#include "Arduino.h"


void stepper_motor::StepperMotorBase::Move(double x, double y, double z, double a) {
    double step_x, step_y, step_z, step_a;
    x *= TOTAL_STEP;
    y *= TOTAL_STEP;
    z *= TOTAL_STEP;
    a *= TOTAL_STEP;
    step_x = -x;
    step_y = -y;
    step_z = -z;
    step_a = -a;
    stepperMove(step_x, step_y, step_z, step_a);
}

void stepper_motor::StepperMotorBase::initMotor() {
    pinMode(EN, OUTPUT);
    digitalWrite(EN, LOW);
    steppers.addStepper(stepper_x);
    steppers.addStepper(stepper_y);
    steppers.addStepper(stepper_z);
    steppers.addStepper(stepper_a);
    stepperSet(V_MAX);
}

void stepper_motor::StepperMotorBase::stepperMove(long _x, long _y, long _z, long _a) {
    long positions[4];
    positions[0] = _x;
    positions[1] = _y;
    positions[2] = _z;
    positions[3] = _a;
    steppers.moveTo(positions);
    steppers.runSpeedToPosition();
    stepper_x.setCurrentPosition(0);
    stepper_y.setCurrentPosition(0);
    stepper_z.setCurrentPosition(0);
    stepper_a.setCurrentPosition(0);
}

void stepper_motor::StepperMotorBase::stepperSet(double _v) {
    stepper_x.setMaxSpeed(_v);
    stepper_y.setMaxSpeed(_v);
    stepper_z.setMaxSpeed(_v);
    stepper_a.setMaxSpeed(_v);
}