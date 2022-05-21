#ifndef CAR_CHASSIS_H_
#define CAR_CHASSIS_H_

#include "RegisterFactory.h"

namespace car_chassis {
    [[maybe_unused]] constexpr int kUltrasonicPin[2] = {A1, A0};
    [[maybe_unused]] constexpr int kOutsideSensorPin[2] = {A3, A10};
    [[maybe_unused]] constexpr int kMedialSensorPin[2] = {A5, A12};
    [[maybe_unused]] constexpr int kSensorPin[4] = {A3, A5, A12, A10};

    enum Directions {
        kForward [[maybe_unused]] = 0x0, kBackward [[maybe_unused]] = 0x1,
        kLeft [[maybe_unused]] = 0x2, kRight [[maybe_unused]] = 0x3,
        kPanLeft [[maybe_unused]] = 0x4, kPanRight [[maybe_unused]] = 0x5,
        SIZE [[maybe_unused]] = 6
    };

    class [[maybe_unused]] CarChassisBase : NO_COPY {
    public:
        [[maybe_unused]] virtual void Initialize() = 0;

        [[maybe_unused]] virtual void AvoidObstacle(int min_distance) = 0;
    };

    using Factory [[maybe_unused]] = RegisterFactory<CarChassisBase>;
    template<typename T> using Registry [[maybe_unused]] = Registry<CarChassisBase, T>;

    [[maybe_unused]] extern Factory &factory;
}

#endif  // CAR_CHASSIS_H_
