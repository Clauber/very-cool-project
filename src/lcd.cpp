#include "lcd.h"

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

void lcdStart()
{
    u8g2.begin();
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_10x20_me);
    u8g2.drawStr(0, 20, "Connecting...");
    u8g2.sendBuffer();
}

void lcdConnected(String ip)
{
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x12_me);
    String message = "IP: " + ip;
    u8g2.drawStr(0, 20, message.c_str());
    u8g2.sendBuffer();
}