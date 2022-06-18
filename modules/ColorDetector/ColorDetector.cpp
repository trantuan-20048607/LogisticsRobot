#include "ColorDetector.h"

int* color_detector::ColorDetectorBase::ColorDetection() {
    if (tcs.begin()) {
        uint16_t clear, red, green, blue;
        tcs.getRawData(&red, &green, &blue, &clear);
        tcs.clearInterrupt();
        uint32_t sum = clear;
        float r, g, b;
        r = red;
        r /= sum;
        r *= 256;
        ColorVal[0] = (int)r;
        g = green; g /= sum;
        g *= 256;
        ColorVal[1] = (int)g;
        b = blue; b /= sum;
        b *= 256;
        ColorVal[2] = (int)b;
        return ColorVal;
    }
    else {                           //如果没有检测到颜色传感器模块
        Serial.println("No TCS34725 found ... check your connections");//串口打印：没有找到颜色识别传感器模块
    }
}

//颜色识别函数
int color_detector::ColorDetectorBase::ColorRecognition(){

    ColorVal[3] = *ColorDetection();
    if(ColorVal[0] >  ColorVal[1] && ColorVal[0] >  ColorVal[2]){ //识别的颜色为红色
//      Serial.println("The color is red!");
        return 1;
    }
    else if(ColorVal[1] >  ColorVal[0] && ColorVal[1] >  ColorVal[2]){ //识别的颜色为绿色
//      Serial.println("The color is green!");
        return 2;
    }
    else if(ColorVal[2] >  ColorVal[0] && ColorVal[2] >  ColorVal[1]){ //识别的颜色为蓝色
//      Serial.println("The color is blue!");
        return 3;
    }
    else{
        return (0);  //其他颜色返回0，排除干扰
    }
}

//连续检测10次，找出检测颜色最多的
int color_detector::ColorDetectorBase::ColorValue(){
    for(int i=0; i<10; i++){
        Color[i] = ColorRecognition();
    }
    return  ModeNum(Color, 10);
}

int color_detector::ColorDetectorBase::ModeNum(int a[],int n){  //求出一组数据中的众数
    int point,times = 0,max;
    int b[10] = {0};
    for(int i = 0; i < n ; i++){
        point = a[i];
        b[point]++;
    }
    for(int j = 0; j < 10 ; j++){
        if(b[j] > times){
            max = j;       //max众数
            times = b[j];  //出现次数
        }
    }
    return max;
}