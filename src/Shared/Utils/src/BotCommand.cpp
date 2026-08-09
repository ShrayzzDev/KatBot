#include "BotCommand.hpp"

std::string toString(BotCommand bc) {
    switch (bc){
    case Up:
        return "Up";
    case Right:
        return "Right";
    case Down:
        return "Down";
    case Left:
        return "Left";
    case Up_Right:
        return "Up Right";
    case Down_Right:
        return "Down Right";
    case Down_Left:
        return "Down Left";
    case Up_Left:
        return "Up Left";
    default:
        return "none";
    }
}