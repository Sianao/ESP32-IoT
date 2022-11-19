#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "WiFi.h"
#include "HTTPClient.h"
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_MOSI   17
#define OLED_CLK    16
#define OLED_DC     18
#define OLED_CS     19
#define OLED_RESET  5
HTTPClient GET ;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
                         OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

const unsigned char electronicshub_logo [] PROGMEM = {

        0XFF,0XFE,0X7F,0XFF,0XFF,0XFE,0X7F,0XFF,0XFF,0XFE,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XF3,0XFF,0XFF,0XCF,0XF1,0XF0,0X0F,0X8F,0XF9,0XC0,0X03,0X9F,0XFF,0X03,0XC1,0XFF,
        0XFE,0X00,0X00,0XFF,0XFE,0X20,0X00,0X7F,0XFC,0X40,0X00,0X3F,0XFC,0X40,0X00,0X3F,
        0XF8,0X80,0X00,0X1F,0XF8,0X00,0X00,0X1F,0XF9,0X00,0X00,0X1F,0X19,0X00,0X00,0X18,
        0X19,0X00,0X00,0X18,0XF9,0X00,0X00,0X1F,0XF8,0X00,0X00,0X1F,0XF8,0X00,0X00,0X1F,
        0XFC,0X00,0X00,0X3F,0XFC,0X00,0X00,0X3F,0XFE,0X00,0X00,0X7F,0XFF,0X00,0X00,0XFF,
        0XFF,0X80,0X01,0XFF,0XF9,0XC0,0X03,0X9F,0XF1,0XF0,0X0F,0X8F,0XF3,0XFF,0XFF,0XCF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X7F,0XFF,0XFF,0XFE,0X7F,0XFF,0XFF,0XFE,0X7F,0XFF,


};
const unsigned char yintian [] PROGMEM={
        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
        0X00,0X00,0X00,0X00,0X00,0X06,0X00,0X00,0X00,0X04,0X00,0X00,0X00,0X00,0XF0,0X00,
        0X00,0X01,0XFC,0X00,0X00,0X03,0XFE,0X00,0X00,0X07,0XFE,0X00,0X00,0X27,0XFE,0X00,
        0X00,0XE7,0XFF,0X00,0X03,0XE7,0XFF,0X00,0X0F,0XE7,0XFF,0X00,0X00,0X07,0XFF,0X00,
        0X00,0X07,0XFF,0XC0,0X07,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XF8,0X1F,0XFF,0XFF,0XFC,
        0X3F,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XFE,0X3F,0XFF,0XFF,0XFE,
        0X3F,0XFF,0XFF,0XFE,0X3F,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XFC,0X1F,0XFF,0XFF,0XFC,
        0X0F,0XFF,0XFF,0XF8,0X07,0XFF,0XFF,0XF0,0X00,0X00,0X0A,0X00,0X00,0X00,0X02,0X00,
};
const char *SSid="SIANA";
const char *Pwd="123456789";
struct tm TimeInfo;
void WIFI_Setup(){
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSid,Pwd);
    while(WiFi.status()!=WL_CONNECTED){
        Serial.print(".");
        delay(500);
    };
    Serial.println(WiFi.localIP());



}
void setup()
{
    Serial.begin(9600);
    if(!display.begin(SSD1306_SWITCHCAPVCC))
    {
        Serial.println(("SSD1306 allocation failed"));
        for(;;);
    }



    display.clearDisplay();
    display.display();
    delay(1000);
    WIFI_Setup();
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.println("Local IP:");
    display.println(WiFi.localIP());
    display.display();
    delay(10000);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    configTime( 8 * 3600,0,"cn.pool.ntp.org");
    if (! getLocalTime(&TimeInfo)){
        Serial.println(("time init failed"));

        return;
    }
    display.printf("%d %d %d\n",TimeInfo.tm_hour,TimeInfo.tm_min,TimeInfo.tm_sec);
    display.display();
    delay(10000);
    display.clearDisplay();
    display.drawBitmap(0, 16, electronicshub_logo, 32, 32, SSD1306_WHITE);
    display.drawBitmap(33, 16, yintian, 32, 32, SSD1306_WHITE);
    display.display();
    delay(10000);


}
void AllPixels()
{
    int i;
    int j;
    display.clearDisplay();
    for(i=0;i<64;i++)
    {
        for(j=0;j<128;j++)
        {
            display.drawPixel(j, i, SSD1306_WHITE);

        }
        display.display();
        delay(30);
    }

    for(i=0;i<64;i++)
    {
        for(j=0;j<128;j++)
        {
            display.drawPixel(j, i, SSD1306_BLACK);

        }
        display.display();
        delay(30);
    }

}

void TextDisplay()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(5,28);
    display.println("Electronics Hub");
    display.display();
    delay(3000);
}

void InvertedTextDisplay()
{
    display.clearDisplay();
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    display.setCursor(5,28);
    display.println("Electronics Hub");
    display.display();
    delay(3000);
}

void ScrollText()
{
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.println("This is a");
    display.println("Scrolling");
    display.println("Text!");
    display.display();
    delay(100);
    display.startscrollright(0x00, 0x0F);
    delay(2000);
    //display.stopscroll();
    //delay(1000);
    display.startscrollleft(0x00, 0x0F);
    delay(2000);
    //display.stopscroll();
    //delay(1000);
    display.startscrolldiagright(0x00, 0x0F);
    delay(2000);
    display.startscrolldiagleft(0x00, 0x0F);
    delay(2000);
    display.stopscroll();
}

void DisplayChars()
{
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.cp437(true);

    for(int16_t i=0; i<256; i++)
    {
        if(i == '\n')
        {
            display.write(' ');
        }
        else
        {
            display.write(i);
        }
    }

    display.display();
    delay(4000);
}
void TextSize()
{
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println(F("Size: 1"));
    display.println(F("ABC"));

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.println("Size: 2");
    display.println(F("ABC"));

    display.display();
    delay(3000);
}

void DrawRectangle()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Rectangle");
    display.drawRect(0, 15, 90, 45, SSD1306_WHITE);
    display.display();
    delay(2000);
}

void DrawFilledRectangle()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Filled Rectangle");
    display.fillRect(0, 15, 90, 45, SSD1306_WHITE);
    display.display();
    delay(2000);

}

void DrawRoundRectangle()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("Round Rectangle");
    display.drawRoundRect(0, 15, 90, 45, 10, SSD1306_WHITE);
    display.display();
    delay(2000);
}

void DrawFilledRoundRectangle()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("Filled Round Rect");
    display.fillRoundRect(0, 15, 90, 45, 10, SSD1306_WHITE);
    display.display();
    delay(2000);

}

void DrawCircle()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("Circle");
    display.drawCircle(30, 36, 25, SSD1306_WHITE);
    display.display();
    delay(2000);
}
void DrawFilledCircle()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("Filled Circle");
    display.fillCircle(30, 36, 25, SSD1306_WHITE);
    display.display();
    delay(2000);

}

void DrawTriangle()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("Triangle");
    display.drawTriangle(30, 15, 0, 60, 60, 60, SSD1306_WHITE);
    display.display();
    delay(2000);
}

void DrawFilledTriangle()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("Filled Triangle");
    display.fillTriangle(30, 15, 0, 60, 60, 60, SSD1306_WHITE);
    display.display();
    delay(2000);
}
void loop()
{
    // AllPixels();
    // TextDisplay();
    // InvertedTextDisplay();
    // ScrollText();
    // DisplayChars();
    // TextSize();
    // DrawRectangle();
    // DrawFilledRectangle();
    // DrawRoundRectangle();
    // DrawFilledRoundRectangle();
    // DrawCircle();
    // DrawFilledCircle();
    // DrawTriangle();
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println(F("Sizefdsfhreoighi: 1"));
    display.println(F("ABC"));

    // DrawFilledTriangle();
}

