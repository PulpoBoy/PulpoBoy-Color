
#define TFT_PIN_CS   10 // CS pin on the display. 
#define TFT_PIN_DC   9  // A0 pin on the display. 
#define TFT_PIN_RST  8  // The reset pin. You can use -1 if it is set to the default arduino reset pin.

#include <SPI.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_ST7735.h>

#include "colors.h"
#include "game.h"

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_PIN_CS, TFT_PIN_DC, TFT_PIN_RST);  

void intro(){

  tft.fillRect(0,0,32,128,ST7735_RED); // Create rainbow
  tft.fillRect(32,0,34,128,ST7735_ORANGE);
  tft.fillRect(64,0,34,128,ST7735_YELLOW);
  tft.fillRect(96,0,34,128,ST7735_GREEN);
  tft.fillRect(128,0,34,128,ST7735_CYAN);

  tft.setTextSize(2);

  tft.setTextWrap(true); 

  tft.setCursor(35,4);
 
  tft.setTextColor(ST7735_WHITE);
  
  
  tft.print("PulpoBoy");

  delay(2000); 

  tft.setCursor(15, 50);
  tft.setTextSize(4);
  tft.print("Color!");

  delay(300);
  tft.invertDisplay(true);
  
  delay(2000);
  tft.invertDisplay(false);
  delay(1000);

  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(15, 50);
  tft.setTextSize(2);
  tft.print("Loading...");
}

void setup() {
  
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  intro();

}

void loop() {
  // put your main code here, to run repeatedly:

}
