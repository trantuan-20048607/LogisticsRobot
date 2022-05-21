#ifndef ROBOT_ARM_H_
#define ROBOT_ARM_H_

#include "RegisterFactory.h"

namespace robot_arm {
    [[maybe_unused]] constexpr int kServoPort[] = {2, 3, 4, 5};

    enum Blocks {
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

    using Factory [[maybe_unused]] = RegisterFactory<RobotArmBase>;
    template<typename T> using Registry [[maybe_unused]] = Registry<RobotArmBase, T>;

    [[maybe_unused]] extern Factory &factory;
}

using Blocks [[maybe_unused]] = robot_arm::Blocks;

#endif  // ROBOT_ARM_H_
