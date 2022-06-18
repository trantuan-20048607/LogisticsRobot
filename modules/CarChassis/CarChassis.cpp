#include "CarChassis.h"
#include "ArduinoLog.h"

[[maybe_unused]] void car_chassis::CarChassis::SetMode(int mode) {
    switch (mode) {
        case 1:
            Right();
            break;
        case 2:
            Left();
            break;
        default:
            Forward();
            break;
    }
}

[[maybe_unused]] long car_chassis::CarChassis::GetDistance(const int *pin) {
    long duration;
    pinMode(pin[1], OUTPUT);
    pinMode(pin[0], INPUT);
    digitalWrite(pin[1], LOW);
    delayMicroseconds(2);
    digitalWrite(pin[1], HIGH);
    delayMicroseconds(20);
    digitalWrite(pin[1], LOW);
    duration = pulseIn(pin[0], HIGH, 1500);
    duration /= 59;
    return (duration < 2 || duration > 200) ? 0 : duration;
}

[[maybe_unused]] int car_chassis::CarChassis::CrossDetect() {
    int s = 0;
    for (auto i = 0; i < 2; i++)
        s |= (digitalRead(kOutsideSensorPin[i]) << i);
    return s;
}

[[maybe_unused]] void car_chassis::CarChassis::AvoidObstacle(int min_distance) {
    if ((GetDistance(kUltrasonicPin) > 2 && GetDistance(kUltrasonicPin) < min_distance)) {
        Forward();
        delay(1000);
        // TODO RobotArm();
        delay(50000);
    } else
        SetMode(CrossDetect());
}

[[maybe_unused]] void car_chassis::CarChassis::PrintDistance() {
    Log.infoln("Distance: %d cm.", GetDistance(kUltrasonicPin));
}

[[maybe_unused]] void car_chassis::CarChassis::PrintGrayValue() {
    Log.infoln("Gray: %d | %d | %d | %d.",
               !(digitalRead(kOutsideSensorPin[0])),
               !(digitalRead(kMedialSensorPin[0])),
               !(digitalRead(kMedialSensorPin[1])),
               !(digitalRead(kOutsideSensorPin[1])));
}

[[maybe_unused]] void car_chassis::CarChassis::Forward(){   //前进
    move(0.105, -0.104, 0.104, -0.1);
}

[[maybe_unused]] void car_chassis::CarChassis::Backward(){  //后退
    move(-0.5, 0.5, -0.5, 0.5);
}

[[maybe_unused]] void car_chassis::CarChassis::Left(){
    move(0.24, 0.24, 0.24, 0.24);
}

[[maybe_unused]] void car_chassis::CarChassis::PanLeft(float v){
    move(v, v, -v, -v);
}

[[maybe_unused]] void car_chassis::CarChassis::Right(){
    move(-0.23, -0.23, -0.23, -0.23);
}

[[maybe_unused]] void car_chassis::CarChassis::PanRight(float v){
    move(-v, -v, v, v);
}

[[maybe_unused]] void car_chassis::CarChassis::Stop(){
    move(0, 0, 0, 0);
}