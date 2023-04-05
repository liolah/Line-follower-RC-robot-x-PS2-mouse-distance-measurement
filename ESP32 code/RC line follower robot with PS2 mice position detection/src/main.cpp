#include <Arduino.h>
#include <PS2MouseHandler.h>
#include <FastLED.h>

#define NUM_LEDS 16
#define DATA_PIN 6

#define MOUSE_0_DATA 5
#define MOUSE_0_CLOCK 6

#define MOUSE_1_DATA 5
#define MOUSE_1_CLOCK 6

PS2MouseHandler mouse0(MOUSE_0_CLOCK, MOUSE_0_DATA, PS2_MOUSE_REMOTE);
PS2MouseHandler mouse1(MOUSE_1_CLOCK, MOUSE_1_DATA, PS2_MOUSE_REMOTE);

bool x_overflow(PS2MouseHandler mouse) {
  return abs(mouse.x_movement()) == 127;
  }

bool y_overflow(PS2MouseHandler mouse) {
  return abs(mouse.y_movement()) == 127;
  }

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  
  xTaskCreatePinnedToCore(
    Task1code, /* Function to implement the task */
    "Task1", /* Name of the task */
    10000,  /* Stack size in words */
    NULL,  /* Task input parameter */
    0,  /* Priority of the task */
    &Task1,  /* Task handle. */
    0); /* Core where the task should run */
}

void loop() {
  // put your main code here, to run repeatedly:
}