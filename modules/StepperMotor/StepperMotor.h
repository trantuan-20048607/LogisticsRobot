#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include <AccelStepper.h>
#include <MultiStepper.h>
#include "DisableConstructors.h"

namespace stepper_motor {
    [[maybe_unused]] constexpr uint8_t kEnablePin = 34;
    [[maybe_unused]] constexpr uint16_t kMaxSpeed = 6400;
    [[maybe_unused]] AccelStepper stepper_x(1, 45, 44);
    [[maybe_unused]] AccelStepper stepper_y(1, 33, 32);
    [[maybe_unused]] AccelStepper stepper_z(1, 43, 42);
    [[maybe_unused]] AccelStepper stepper_a(1, 31, 30);
    [[maybe_unused]] MultiStepper steppers;

    class [[maybe_unused]] StepperMotorBase : NO_COPY {
    public:
        [[maybe_unused]] virtual void Initialize() = 0;

        [[maybe_unused]] static void Move(double x, double y, double z, double a);

        [[maybe_unused]] void initMotor();

        [[maybe_unused]] void stepperMove(long _x, long _y, long _z, long _a);

        [[maybe_unused]] void stepperSet(double _v);
    };
}
#define V_MAX 20
#define EN 34
#define TOTAL_STEP 3200;

#endif  // STEPPER_MOTOR_H_
