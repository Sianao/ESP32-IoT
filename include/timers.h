//
// Created by Sanse on 2022/11/30.
//

#ifndef ESP32_IOT_TIMERS_H
#define ESP32_IOT_TIMERS_H

#include "Arduino.h"
#include "weather.h"
#include "http.h"

struct tm TimeInfo;

void TimeSync() {
    configTime(8 * 3600, 0, "1.cn.pool.ntp.org","3.cn.pool.ntp.org");
    if (!getLocalTime(&TimeInfo)) {
        Serial.println(("time init failed"));
        return;
    }


}

void TimeShow() {
    display.clearDisplay();
    //定位图标
    display.drawBitmap(0, 0, localtion, 16, 16, SSD1306_WHITE);
    //重chong
    display.setCursor(17, 0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.write("CHONG");
    //庆Qing
    display.setCursor(17, 8);
    display.write("QING");
    display.setCursor(55, 8);
    display.setTextSize(1);
    display.printf("%d-%d-%d", TimeInfo.tm_year + 1900, TimeInfo.tm_mon+1, TimeInfo.tm_mday);

    switch (Now.code) {
        // 晴天
        case 0:
            display.drawBitmap(9, 17, sun, 32, 32, SSD1306_WHITE);
            display.drawBitmap(9, 48, sunn, 32, 16, SSD1306_WHITE);
            break;
            //多云
        case 4:
            display.drawBitmap(9, 17, duoyun, 32, 32, SSD1306_WHITE);
            display.drawBitmap(9, 48, duoyunword, 32, 16, SSD1306_WHITE);

            break;
        case 9:
            display.drawBitmap(9, 17, yin, 32, 32, SSD1306_WHITE);
            display.drawBitmap(9, 48, yingtianword, 32, 16, SSD1306_WHITE);

            break;
        case 13:
            display.drawBitmap(9, 17, xiaoyu, 32, 32, SSD1306_WHITE);
            display.drawBitmap(9, 48, xaioyuword, 32, 16, SSD1306_WHITE);

            break;
        case 14:
            display.drawBitmap(9, 17, zhongyu, 32, 32, SSD1306_WHITE);
            display.drawBitmap(9, 48, zhongyuword, 32, 16, SSD1306_WHITE);

            break;
        case 15:
        case 16:
        case 17:
        case 18:
            display.drawBitmap(9, 17, dayu, 32, 32, SSD1306_WHITE);
            display.drawBitmap(9, 48, dayuword, 32, 16, SSD1306_WHITE);

            break;
        case 20:
            display.drawBitmap(9, 17, yujiaxue, 32, 32, SSD1306_WHITE);
            display.drawBitmap(9, 48, yuxue, 32, 16, SSD1306_WHITE);

            break;
        case 22:
            display.drawBitmap(9, 17, xiaoxue, 32, 32, SSD1306_WHITE);
            display.drawBitmap(9, 48, xiaoxueworld, 32, 16, SSD1306_WHITE);

            break;
        case 23:
            display.drawBitmap(9, 17, zhongxue, 32, 32, SSD1306_WHITE);
            display.drawBitmap(9, 48, zhognxuewor, 32, 16, SSD1306_WHITE);

        case 24:
        case 25:
            display.drawBitmap(9, 17, daxue, 32, 32, SSD1306_WHITE);
            display.drawBitmap(9, 48, daxueworld, 32, 16, SSD1306_WHITE);

            break;


    }

    if (!getLocalTime(&TimeInfo)) {
        Serial.println(("time init failed"));
        return;
    }

    display.drawBitmap(48, 21, temprte, 16, 16, SSD1306_WHITE);
    display.setCursor(48 + 16, 21);
    display.setTextSize(2);
    display.printf("%d",Now.temperature);
    display.drawBitmap(48,43,clocks,16,16,SSD1306_WHITE);
    display.setCursor(48 + 17, 43);
    display.setTextSize(2);
    display.drawBitmap(48+16+2*16,21,OC,32,16,SSD1306_WHITE);
    display.printf("%d:%d",TimeInfo.tm_hour,TimeInfo.tm_min);

    display.display();
}


#endif //ESP32_IOT_TIMERS_H
