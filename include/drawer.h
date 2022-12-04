//
// Created by Sanse on 2022/11/30.
//

#ifndef ESP32_IOT_DRAWER_H
#define ESP32_IOT_DRAWER_H


#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "Image.h"
#include "WiFi.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_MOSI   17
#define OLED_CLK    16
#define OLED_DC     18
#define OLED_CS     19
#define OLED_RESET  5
////TwoWire *wr;
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
//                         OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void DrawerInit() {

//    if (!display.begin(SSD1306_SWITCHCAPVCC)) {
//        Serial.println(("SSD1306 init failed"));
//        for (;;);
//    }
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }
}

void WaitCon() {
    display.clearDisplay();
    display.drawBitmap(32, 16, Duoyun, 32, 32, SSD1306_WHITE);
    display.setCursor(65, 16 + 8);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.write("Waiting");
    display.drawFastHLine(0, 0, 128, SSD1306_WHITE);
    display.drawFastHLine(0, 63, 128, SSD1306_WHITE);
    display.setCursor(65, 16 + 8 + 8);
    display.write("Connect");
    display.display();
}

void Connected() {
    display.clearDisplay();
    display.drawBitmap(0, 16, Conn, 32, 32, SSD1306_WHITE);
    display.setCursor(33, 16);
    display.setTextSize(1);
    WiFi.mode(WIFI_STA);
    display.setTextColor(SSD1306_WHITE);
    display.write("Cool It Works");
    display.setCursor(33, 16 + 8);
    display.write("Wifi IP:");
    display.setCursor(33, 16 + 8 + 8);
    display.write(WiFi.localIP().toString().c_str());
    display.setCursor(33, 16 + 8 + 8 + 8);
    display.write("SSID:");
    display.write(WiFi.SSID().c_str());
    display.display();

}

#endif //ESP32_IOT_DRAWER_H
