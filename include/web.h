//
// Created by Sanse on 2022/11/29.
//
#ifndef ESP32_IOT_WEB_H
#define ESP32_IOT_WEB_H
#include "Arduino.h"
#include "WiFi.h"
#include "cJSON.h"
#include <cstring>
#include "http.h"

typedef struct Weather {
    int code;
    int temperature;
    int state;
} Weather;

Weather GetWeather() {
    HTTPClient client;
    client.begin("https://api.seniverse.com/v3/weather/"
                 "now.json?key=S2hXEYH4slFO1XyJY&location"
                 "=chongqing&language=zh-Hans&unit=c");
    Weather weather;
    int httpCode = client.GET();
    String resBuff;
    Serial.printf("HTTP  StateCode: %d\n", httpCode);
    if (httpCode == HTTP_CODE_OK) // 收到正确的内容
    {
        resBuff = client.getString();
    }

    cJSON *root = cJSON_Parse(resBuff.c_str());
    if (root == nullptr) {
        weather.state = -1;
        return weather;
    }
    cJSON *result_array = cJSON_GetObjectItem(root, "results");
    if (result_array == nullptr) {
        weather.state = -1;
        return weather;
    }
    cJSON *result = cJSON_GetArrayItem(result_array, 0);
    if (result == nullptr) {
        weather.state = -1;
        return weather;
    }
    cJSON *now = cJSON_GetObjectItem(result, "now");
    if (now == nullptr) {
        weather.state = -1;
        return weather;
    }
    cJSON *code = cJSON_GetObjectItem(now, "code");
    if (code == nullptr) {
        weather.state = -1;
        return weather;
    }
    cJSON *temperature = cJSON_GetObjectItem(now, "temperature");
    if (temperature == nullptr) {
        weather.state = -1;
        return weather;
    }
   if (cJSON_IsString(temperature)){
       Serial.println(temperature->valuestring);
       weather.temperature= std::stoi(temperature->valuestring);
   }
   if(cJSON_IsString(code)){
       Serial.println(code->valuestring);
       weather.code=std::stoi(code->valuestring);
   }

    Serial.println(cJSON_Print(now));
    return weather;
}

#endif //ESP32_IOT_WEB_H
