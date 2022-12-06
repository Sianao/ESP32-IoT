//
// Created by Sanse on 2022/11/30.
//

#ifndef ESP32_IOT_HTTP_H
#define ESP32_IOT_HTTP_H

#include "web.h"
#include "drawer.h"
#include "HTTPClient.h"
#include "Ticker.h"

Ticker WeaTick;

void Callback() {
    Now = GetWeather();
}

void WeatherTicker() {
    Now = GetWeather();
    WeaTick.attach(60 * 60, Callback);
    WeaTick.active();
}

#endif //ESP32_IOT_HTTP_H
