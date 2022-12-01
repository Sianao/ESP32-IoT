//
// Created by Sanse on 2022/11/30.
//

#ifndef ESP32_IOT_HTTP_H
#define ESP32_IOT_HTTP_H
#include "drawer.h"
#include "HTTPClient.h"
#include "web.h"

void SH() {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    Weather w = GetWeather();
    if (w.state == -1) {
        display.printf("%d \n", w.state);

    } else {
        display.printf("%d %d \n", w.temperature, w.code);
    }
    display.println("hello");
    display.display();
//    delay(20000);
}

#endif //ESP32_IOT_HTTP_H
