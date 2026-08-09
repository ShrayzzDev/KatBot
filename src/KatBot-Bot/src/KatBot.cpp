#include "./headers/KatBot.hpp"

void KatBot::InitBt() {
  this->m_bt.begin("Magnificent Tool Of Destruction", true);

  this->m_logger->println("Magnificent Tool Of Destruction has started\n");

  for (short i = 0; i < 1; ++i) {
    while (!this->m_bt.connect(addresses[i])) { 
        this->m_logger->printf("Connecting to the controller n°%d . . .", i);
    }
  }

  this->m_logger->printf("Connected to all controllers !");
}

void KatBot::InitPins() {
    // empty atm, only the board
}

KatBot::KatBot() : KatBot(&Serial) {
    Serial.begin(9600);
}

KatBot::KatBot(Print* printer) : Device(printer) {
    InitBt();
    InitPins();
}

void KatBot::CheckInputs() {
  if (this->m_bt.available()) {
    this->m_logger->println(this->m_bt.read());
  }
}