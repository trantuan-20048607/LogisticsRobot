#include "ColorDetector.h"

int *color_detector::ColorDetectorBase::ColorDetection() {
    if (tcs.begin()) {
        uint16_t clear, red, green, blue;
        tcs.getRawData(&red, &green, &blue, &clear);
        tcs.clearInterrupt();
        uint32_t sum = clear;
        ColorVal[0] = int(256 * (red / sum));
        ColorVal[1] = int(256 * (green / sum));
        ColorVal[2] = int(256 * (blue / sum));;
        return ColorVal;
    } else {
        Serial.println("No TCS34725 found ... check your connections");
    }
}

int color_detector::ColorDetectorBase::ColorRecognition() {
    ColorVal[3] = *ColorDetection();
    if (ColorVal[0] > ColorVal[1] && ColorVal[0] > ColorVal[2]) {
        return 1;
    } else if (ColorVal[1] > ColorVal[0] && ColorVal[1] > ColorVal[2]) {
        return 2;
    } else if (ColorVal[2] > ColorVal[0] && ColorVal[2] > ColorVal[1]) {
        return 3;
    } else {
        return (0);
    }
}

Colors color_detector::ColorDetectorBase::ColorValue() {
    for (int i = 0; i < 10; ++i)
        Color[i] = ColorRecognition();
    return ModeNum(Color, 10);
}

Colors color_detector::ColorDetectorBase::ModeNum(int a[], int n) {
    int b[4], ans, tmp = 0;
    for (int i = 0; i < n; ++i)
        b[a[i]]++;
    for (int j = 0; j < 4; ++j)
        if (b[j] > tmp)
            ans = j, tmp = b[j];
    switch (ans) {
        case 0 :
            return Colors::kNone;
        case 1 :
            return Colors::kRed;
        case 2 :
            return Colors::kGreen;
        case 3 :
            return Colors::kBlue;
        default :
            break;
    }
}