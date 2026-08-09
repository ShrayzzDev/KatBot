#include <Arduino.h>
#include <BluetoothSerial.h>

#include "./headers/KatBot.hpp"

// Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif

KatBot kat;

void setup() {
}

void loop() {
  kat.CheckInputs();
  delay(20);
}