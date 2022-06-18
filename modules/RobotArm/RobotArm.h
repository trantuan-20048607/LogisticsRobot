#ifndef ROBOT_ARM_H_
#define ROBOT_ARM_H_

#include "DisableConstructors.h"
#include "ColorDetector.h"
#include <ServoTimer2.h>

namespace robot_arm {
    [[maybe_unused]] constexpr int kServoPort[] = {2, 3, 4, 5};
    [[maybe_unused]] constexpr int kServoNum = 4;
    [[maybe_unused]] constexpr int kDivPartNum = 4;
    enum class Blocks {
        kNone [[maybe_unused]] = 0x0,
        kBlockA [[maybe_unused]] = 0x1,
        kBlockB [[maybe_unused]] = 0x2,
        kBlockC [[maybe_unused]] = 0x3,
        SIZE [[maybe_unused]] = 4
    };

    class [[maybe_unused]] RobotArmBase : NO_COPY {
    public:

        [[maybe_unused]]  virtual void Initialize() = 0;

        [[maybe_unused]]  virtual void Run() = 0;

        RobotArmBase() :
                servo_() {}

        [[maybe_unused]] void Handle(Blocks block);

        [[maybe_unused]] void Grab(Blocks block);

        [[maybe_unused]] void Place(color_detector::Colors color);

        [[maybe_unused]] void ServoStart(int index);

        [[maybe_unused]] void ServoStop(int index);

        [[maybe_unused]] void ServoGo(int index, int dest);

        [[maybe_unused]] void ServoMove(float v1, float v2, float v3, float v4);

        [[maybe_unused]] ServoTimer2 servo_[kServoNum];

        [[maybe_unused]]  float servo_value_[kServoNum]{1500, 1850, 860, 1800};

    };
}

using Blocks [[maybe_unused]] = robot_arm::Blocks;

#endif  // ROBOT_ARM_H_
