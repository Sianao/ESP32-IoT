//
// Created by Sanse on 2022/11/30.
//

#ifndef ESP32_IOT_HTTP_H
#define ESP32_IOT_HTTP_H

#include "web.h"
#include "drawer.h"
#include "HTTPClient.h"

void SH() {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    Now = GetWeather();
    if (Now.state == -1) {
        display.printf("%d \n", Now.state);
    } else {
        display.printf("%d %d \n", Now.temperature, Now.code);
    }
    display.println("hello");
    display.display();
    delay(5000);
}

#endif //ESP32_IOT_HTTP_H
