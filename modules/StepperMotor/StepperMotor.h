#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include <AccelStepper.h>
#include <MultiStepper.h>
#include "RegisterFactory.h"

namespace stepper_motor {
    [[maybe_unused]] constexpr uint8_t kEnablePin = 34;
    [[maybe_unused]] constexpr uint16_t kMaxSpeed = 6400;

    class [[maybe_unused]] StepperMotorBase : NO_COPY {
    public:
        [[maybe_unused]] virtual void Initialize() = 0;

        [[maybe_unused]] virtual void Move(double x, double y, double z, double a) = 0;
    };

    using Factory [[maybe_unused]] = RegisterFactory<StepperMotorBase>;
    template<typename T> using Registry [[maybe_unused]] = Registry<StepperMotorBase, T>;

    [[maybe_unused]] extern Factory &factory;
}

#endif  // STEPPER_MOTOR_H_
