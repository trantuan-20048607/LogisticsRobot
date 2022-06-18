#ifndef COLOR_DETECTOR_H_
#define COLOR_DETECTOR_H_

#include <Adafruit_TCS34725.h>
#include "DisableConstructors.h"


namespace color_detector {
    [[maybe_unused]] constexpr auto kTcsIntegrationTime = TCS34725_INTEGRATIONTIME_50MS;
    [[maybe_unused]] constexpr auto kTcsGain = TCS34725_GAIN_4X;
    [[maybe_unused]] Adafruit_TCS34725 tcs = Adafruit_TCS34725(kTcsIntegrationTime,kTcsGain);
    [[maybe_unused]] int ColorVal[] = {0, 0, 0};
    [[maybe_unused]] int Color[]={0,0,0,0,0,0,0,0,0,0};
    enum class Colors {
        kNone [[maybe_unused]] = 0x0,
        kRed [[maybe_unused]] = 0x1,
        kGreen [[maybe_unused]] = 0x2,
        kBlue [[maybe_unused]] = 0x3,
        SIZE [[maybe_unused]] = 0x4
    };

    class ColorDetectorBase : NO_COPY {
    public:
        [[maybe_unused]] Colors GetColor;


        [[maybe_unused]] int* ColorDetection();
        [[maybe_unused]] int ColorRecognition();
        [[maybe_unused]] int ColorValue();
        [[maybe_unused]] int ModeNum(int a[],int n);

        ColorDetectorBase() :
                adafruit_tcs_34725_(kTcsIntegrationTime, kTcsGain) {}

        [[maybe_unused]] Adafruit_TCS34725 adafruit_tcs_34725_;
    };
}

using Colors [[maybe_unused]] = color_detector::Colors;

#endif  // COLOR_DETECTOR_H_
