#include <string>

enum BotCommand {
    Up,
    Right,
    Down,
    Left,
    Up_Right,
    Down_Right,
    Down_Left,
    Up_Left
};

//mainly for debug purposes
std::string toString(BotCommand bc);