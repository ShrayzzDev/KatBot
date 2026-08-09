#include "./headers/Controller.hpp"
#include "BotCommand.hpp"

void Controller::InitBt()
{
    this->m_bt.begin("KatBot-Controller");
}

void Controller::InitPins()
{
  pinMode(BLUETOOTH_LED, OUTPUT);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);
  pinMode(BUTTON_UP, INPUT_PULLUP);
}

Controller::Controller() : Controller(&Serial) {
    Serial.begin(9600);
}

Controller::Controller(Print* printer) : Device(printer) {
    InitBt();
    InitPins();
}

void Controller::CheckInput() {
    BotCommand bc;
    if (!digitalRead(BUTTON_DOWN)) {
        if (!digitalRead(BUTTON_LEFT)) {
            bc = Down_Left;
        } else if (!digitalRead(BUTTON_RIGHT)) {
            bc = Down_Right;
        } else {
            bc = Down;
        }
    }
    if (!digitalRead(BUTTON_UP)) {
        if (!digitalRead(BUTTON_LEFT)) {
            bc = Up_Left;
        } else if (!digitalRead(BUTTON_RIGHT)) {
            bc = Up_Right;
        } else {
            bc = Up;
        }
    }
    if (!digitalRead(BUTTON_RIGHT)) {
        bc = Right;
    }    
    if (!digitalRead(BUTTON_LEFT)) {
        bc = Left;
    }
    m_logger->println(toString(bc).c_str());
    m_bt.write(bc);
}

Controller::~Controller()
{
    this->m_bt.~BluetoothSerial();
}
