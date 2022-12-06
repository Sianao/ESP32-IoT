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
// ������ IoT
// �Զ�У׼ʱ��
// �Զ���ȡ����
// ����ʱ��
// �����Ѻ���
//

