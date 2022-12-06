#include "Arduino.h"
#include "vlan.h"
#include "drawer.h"
#include "timers.h"
#include "http.h"

void setup() {
    Serial.begin(115200);

    DrawerInit();
    WaitCon();
    delay(2000);
    WIFI_Setup();
    Connected();
    delay(2000);
    TimeSync();
    WeatherTicker();
}

void loop() {
    TimeShow();
}
// 联网的 IoT
// 自动校准时间
// 自动获取天气
// 天气时钟
// 界面友好型
//

