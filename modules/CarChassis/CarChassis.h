#ifndef CAR_CHASSIS_H_
#define CAR_CHASSIS_H_

#include <pins_arduino.h>
#include "DisableConstructors.h"

namespace car_chassis {
    [[maybe_unused]] constexpr int kUltrasonicPin[2] = {A1, A0};
    [[maybe_unused]] constexpr int kOutsideSensorPin[2] = {A3, A10};
    [[maybe_unused]] constexpr int kMedialSensorPin[2] = {A5, A12};
    [[maybe_unused]] constexpr int kSensorPin[4] = {A3, A5, A12, A10};

    enum class Directions {
        kForward [[maybe_unused]] = 0x0, kBackward [[maybe_unused]] = 0x1,
        kLeft [[maybe_unused]] = 0x2, kRight [[maybe_unused]] = 0x3,
        kPanLeft [[maybe_unused]] = 0x4, kPanRight [[maybe_unused]] = 0x5,
        SIZE [[maybe_unused]] = 6
    };

    class [[maybe_unused]] CarChassis : NO_COPY {
    public:
        [[maybe_unused]] virtual void Initialize() = 0;

        [[maybe_unused]] virtual void AvoidObstacle(int min_distance) = 0;

        [[maybe_unused]] void SetMode(int mode);

        [[maybe_unused]] long GetDistance(const int *pin);

        [[maybe_unused]] int CrossDetect();

        [[maybe_unused]] void PrintDistance();

        [[maybe_unused]] void PrintGrayValue();


        //chassis move model
        [[maybe_unused]] void Forward();

        [[maybe_unused]] void Backward();

        [[maybe_unused]] void Left();

        [[maybe_unused]] void PanLeft(float v);

        [[maybe_unused]] void Right();

        [[maybe_unused]] void PanRight(float v);

        [[maybe_unused]] void Stop();
    };
}

using Directions [[maybe_unused]] = car_chassis::Directions;

#endif  // CAR_CHASSIS_H_
