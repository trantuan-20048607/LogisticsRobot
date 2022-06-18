#include <ArduinoLog.h>
#include "StepperMotor.h"
#include "CarChassis.h"
#include "ColorDetector.h"
#include "RobotArm.h"

constexpr uint32_t kBaudRate = 9600;
[[maybe_unused]] constexpr int kMinDistance = 5;

void setup() {
    Serial.begin(kBaudRate);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);

    for (auto i = 0; i < 2; i++) {
        pinMode(car_chassis::kOutsideSensorPin[i], INPUT);
        pinMode(car_chassis::kMedialSensorPin[i], INPUT);
    }
}

void loop() {

}
