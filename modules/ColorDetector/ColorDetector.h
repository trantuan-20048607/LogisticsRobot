#ifndef COLOR_DETECTOR_H_
#define COLOR_DETECTOR_H_

#include <Adafruit_TCS34725.h>
#include "RegisterFactory.h"

namespace color_detector {
    [[maybe_unused]] constexpr auto kTcsIntegrationTime = TCS34725_INTEGRATIONTIME_50MS;
    [[maybe_unused]] constexpr auto kTcsGain = TCS34725_GAIN_4X;

    enum Colors {
        kNone [[maybe_unused]] = 0x0,
        kRed [[maybe_unused]] = 0x1,
        kGreen [[maybe_unused]] = 0x2,
        kBlue [[maybe_unused]] = 0x3,
        SIZE [[maybe_unused]] = 0x4
    };

    class ColorDetectorBase : NO_COPY {
    public:
        [[maybe_unused]] virtual Colors GetColor() = 0;

    protected:
        ColorDetectorBase() :
                adafruit_tcs_34725_(kTcsIntegrationTime, kTcsGain) {}

        [[maybe_unused]] Adafruit_TCS34725 adafruit_tcs_34725_;
    };

    using Factory [[maybe_unused]] = RegisterFactory<ColorDetectorBase>;
    template<typename T> using Registry [[maybe_unused]] = Registry<ColorDetectorBase, T>;

    [[maybe_unused]] extern Factory &factory;
}

using Colors [[maybe_unused]] = color_detector::Colors;

#endif  // COLOR_DETECTOR_H_
