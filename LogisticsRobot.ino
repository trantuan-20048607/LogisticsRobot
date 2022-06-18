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
    car_chassis::CarChassis myCarChassis;
    stepper_motor::StepperMotorBase myStepperMotor;
    color_detector::ColorDetectorBase myColorDetector;
    robot_arm::RobotArmBase myRobotArm;
    myCarChassis.Initialize();
    myStepperMotor.Initialize();
    myStepperMotor.initMotor();
    //寻迹
    while (myCarChassis.GetDistance(car_chassis::kUltrasonicPin)) {
        myCarChassis.AvoidObstacle(200);
        myCarChassis.PrintDistance();
        myCarChassis.PrintGrayValue();
    }
    for (auto i = 0; i < 3; ++i) {
        myRobotArm.Initialize();
        myColorDetector.ColorValue();
    }
}
