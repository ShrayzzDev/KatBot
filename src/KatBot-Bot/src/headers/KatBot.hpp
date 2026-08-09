#include "Device.hpp"

class KatBot : public Device {
    private:
        void InitBt();
        void InitPins();
        uint8_t addresses[1][8] = {
            {0x30,0x76,0xf5,0x90,0xe0,0x1A}
        };
    public :
        KatBot();
        void CheckInputs();
        KatBot(Print* printer);
};