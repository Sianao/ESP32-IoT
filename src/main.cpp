#include "Arduino.h"
#include "vlan.h"
#include "drawer.h"
#include "timers.h"
#include "http.h"

void setup() {
    Serial.begin(115200);

    DrawerInit();
    WaitCon();
    WIFI_Setup();
    Connected();
    TimeSync();
//    hw_timer_t *timer=timerBegin(0,80, true);
    SH();
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

