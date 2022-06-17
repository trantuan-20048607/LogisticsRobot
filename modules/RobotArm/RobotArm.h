#ifndef ROBOT_ARM_H_
#define ROBOT_ARM_H_

#include "DisableConstructors.h"

namespace robot_arm {
    [[maybe_unused]] constexpr int kServoPort[] = {2, 3, 4, 5};

    enum class Blocks {
        kNone [[maybe_unused]] = 0x0,
        kBlockA [[maybe_unused]] = 0x1,
        kBlockB [[maybe_unused]] = 0x2,
        kBlockC [[maybe_unused]] = 0x3,
        SIZE [[maybe_unused]] = 4
    };

    class [[maybe_unused]] RobotArmBase : NO_COPY {
    public:
        [[maybe_unused]] virtual void Initialize() = 0;

        [[maybe_unused]] virtual void Run() = 0;
    };
}

using Blocks [[maybe_unused]] = robot_arm::Blocks;

#endif  // ROBOT_ARM_H_
