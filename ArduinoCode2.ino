#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
// Define global variables
volatile int count = 0;
// Initialize LCD object for software SPI
// Adafruit_PCD8544(CLK,DIN,D/C,CE,RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup() {
  // Set up serial communication at 9600 baud rate
  Serial.begin(9600);  //To send count to serial bus

  // Set up for Encoder
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), countRisingEdge, RISING);  //when interrupt, trigger countRisingEdge function. Interrupt in mode "Rising"

  //Set up for 5110
  display.begin();
  
}

void loop() {
  //Do nothing
  //delay(1000);
  // Display Text
}

void countRisingEdge() {
  // Increment the count variable
  count++;
  Serial.print("Count: ");
  Serial.println(count);
  display5110();
}

void display5110(){
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0, 0);
  display.println("Length : ");
  display.println(count);
  display.display();
  delay(2000);
  display.clearDisplay();
}