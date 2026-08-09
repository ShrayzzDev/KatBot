#include <Arduino.h>
#include <BluetoothSerial.h>

#include "./headers/Controller.hpp"

// Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to enable it
#endif

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif

Controller controller;

void setup() {
}

void loop() {
  controller.CheckInput();
  delay(10);
}   