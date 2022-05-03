/*
 * Copyright (C) 2022  Alexey Pavlov <pezeleha@duck.com>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the 
 * GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or 
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along with this program. If not, see 
 * <https://www.gnu.org/licenses/>. 
 * 
 */
#define TFT_PIN_CS   10 // CS pin on the display. 
#define TFT_PIN_DC   9  // A0 pin on the display. 
#define TFT_PIN_RST  8  // The reset pin. You can use -1 if it is set to the default arduino reset pin.

#define JOYSTICK_SW   2
#define JOYSTICK_VRx A0
#define JOYSTICK_VRy A1

#include <SPI.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_ST7735.h>
#include <AxisJoystick.h>

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_PIN_CS, TFT_PIN_DC, TFT_PIN_RST);
AxisJoystick joystick(JOYSTICK_SW, JOYSTICK_VRx, JOYSTICK_VRy);

enum Move {
    PRESS, UP, DOWN, RIGHT, LEFT, NOT
};

#include "colors.h"
#include "game.h"
#include "mokoto_glitch.h"
#include "pulpo_boy_logo.h"

int joystickX;
int joystickY;



void intro(){

  tft.fillRect(0,0,32,128,ST7735_RED); // Create rainbow
  delay(100);
  tft.fillRect(32,0,34,128,ST7735_ORANGE);
  delay(100);
  tft.fillRect(64,0,34,128,ST7735_YELLOW);
  delay(100);
  tft.fillRect(96,0,34,128,ST7735_GREEN);
  delay(100);
  tft.fillRect(128,0,34,128,ST7735_CYAN);
  delay(200);

  
  tft.setFont(&Mokoto_Glitch6pt7b);

  tft.setTextWrap(true); 

  tft.setCursor(35,20);
 
  tft.setTextColor(ST7735_WHITE);
  
  
  tft.print("P");
  delay(100);
  tft.print("u");
  delay(100);
  tft.print("l");
  delay(100);
  tft.print("p");
  delay(100);
  tft.print("o");
  delay(100);
  tft.print("B");
  delay(100);
  tft.print("o");
  delay(100);
  tft.print("y");
  delay(100);

  delay(2000); 

  tft.setCursor(25, 70);
  tft.setTextSize(2);
  tft.print("Color!");

  delay(300);
  tft.invertDisplay(true);
  
  delay(1000);
  tft.invertDisplay(false);
  delay(1000);
  
  tft.fillRect(0,0,32,128,ST7735_RED); // Create rainbow
  tft.fillRect(32,0,34,128,ST7735_ORANGE);
  tft.fillRect(64,0,34,128,ST7735_YELLOW);
  tft.fillRect(96,0,34,128,ST7735_GREEN);
  tft.fillRect(128,0,34,128,ST7735_CYAN);

  tft.drawBitmap(0,0,pulpo_boy_logo, 160,128,ST7735_BLACK);

  delay(3000);

  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(10, 50);
  tft.print("Loading");
}

void setup() {
  
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  intro();
  setup_game();
  display_game_logo();

}

void loop() {
  update_game();
  draw_game();
  delay_game();

}
