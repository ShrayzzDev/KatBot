#include <BluetoothSerial.h>

class Device {
    protected:
        Print* m_logger;
        BluetoothSerial m_bt;
        virtual void InitBt() = 0;
        virtual void InitPins() = 0;
        // Uses a user defined logger.
        Device(Print* printer);
};