#include "Device.hpp"

#define BLUETOOTH_LED 18
#define BUTTON_DOWN 19
#define BUTTON_LEFT 21
#define BUTTON_RIGHT 22
#define BUTTON_UP 23

class Controller : public Device {
    private:
        void InitBt();
        void InitPins();
    public:
        // Constructs a controller with Serial as the logger
        Controller();
        // Uses a user defined logger.
        Controller(Print* printer);
        // Checks user input and sends the results via bluetooth if anything found
        void CheckInput();
        ~Controller();
};