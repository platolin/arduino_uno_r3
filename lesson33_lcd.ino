/******************************************************************************
----------------本例程仅供学习使用，未经作者允许，不得用于其他用途。-----------
------------------------版权所有，仿冒必究！-----------------------------------
----------------1.开发环境:Arduino IDE-----------------------------------------
----------------2.测试使用开发板型号：Arduino Leonardo or Arduino UNO R3-------
----------------3.单片机使用晶振：16M------------------------------------------
----------------4.淘宝网址：Ilovemcu.taobao.com--------------------------------
----------------------------epic-mcu.taobao.com--------------------------------
----------------5.作者：神秘藏宝室---------------------------------------------
******************************************************************************/
#include <Arduino.h>
#include <Wire.h>  // Arduino IDE 內建
#include "DHT11.h"
#include <LiquidCrystal_I2C.h>

DHT11 myDHT11(2);

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // 設定 LCD I2C 位址

void setup()			//Arduino程序初始化程序放在这里，只在开机时候运行一次
{							
  Serial.begin(115200);  // 用於手動輸入文字
  lcd.begin(16, 2);      // 初始化 LCD，一行 16 的字元，共 2 行，預設開啟背光

  // 閃爍三次=+
  for(int i = 0; i < 3; i++) {
    lcd.backlight(); // 開啟背光
    delay(250);
    lcd.noBacklight(); // 關閉背光
    delay(250);
  }
  lcd.backlight();

  // 輸出初始化文字
  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
  lcd.print("Hello, world!");
  delay(1000);
  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
  lcd.print("plato ");
  delay(8000);

}

void loop()			//Arduino程序的主程序部分，循环运行内部程序
{
    delay(5000);			  //延时10s
    // 清除舊訊息
    lcd.clear();
    // read DHT11 data 
    myDHT11.DHT11_Read();								//读取温湿度值
     // 將訊息顯示在 LCD 上
     lcd.setCursor(0, 0); // 設定游標位置在第一行行首
     lcd.write("HUMI = " + myDHT11.HUMI_Buffer_Int );    
     lcd.setCursor(0, 1); // 設定游標位置在第二行行首
     lcd.write("TEMP = " + myDHT11.TEM_Buffer_Int ); 
}
