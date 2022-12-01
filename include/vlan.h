//
// Created by Sanse on 2022/11/30.
//

#ifndef ESP32_IOT_VLAN_H
#define ESP32_IOT_VLAN_H
#include "WiFi.h"
const char *SSid = "Mi 11 Ultra";
const char *Pwd = "123456789";
void WIFI_Setup() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSid, Pwd);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    };
    Serial.println(WiFi.localIP());
    Serial.println(WiFi.dnsIP());
}

#endif //ESP32_IOT_VLAN_H
