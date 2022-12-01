//
// Created by Sanse on 2022/11/30.
//

#ifndef ESP32_IOT_TIMERS_H
#define ESP32_IOT_TIMERS_H
#include "Arduino.h"
#include "weather.h"
struct tm TimeInfo;
void TimeSync() {
    configTime(8 * 3600, 0, "cn.pool.ntp.org");
    if (!getLocalTime(&TimeInfo)) {
        Serial.println(("time init failed"));
        return;
    }


}
void TimeShow() {
    display.clearDisplay();
    //定位图标
    display.drawBitmap(0,0,localtion,16,16,SSD1306_WHITE);
    //重chong
    display.setCursor(17, 0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.write("CHONG");
    //庆Qing
    display.setCursor(17,8);
    display.write("QING");
    display.setCursor(50,0);
    display.setTextSize(1);
    display.printf("%d-%d-%d",TimeInfo.tm_year+1900,TimeInfo.tm_mon,TimeInfo.tm_mday);
    display.drawBitmap(9,17,sun,32,32,SSD1306_WHITE);
//    display.setCursor()
//    if (!getLocalTime(&TimeInfo)) {
//        Serial.println(("time init failed"));
//        return;
//    }
//    display.printf("%d-%d-%d\n", TimeInfo.tm_hour, TimeInfo.tm_min, TimeInfo.tm_sec);
    display.display();
}


#endif //ESP32_IOT_TIMERS_H
