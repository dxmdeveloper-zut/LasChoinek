#include "terminal.hpp"
#include "rgb.hpp"
#include <string>
#include <stdio.h>

static std::string _setColorEsc(RGB color, char mode){
    char command[] = "\033[%hhu;2;%hhu;%hhu;%hhum";
    sprintf(command, command, mode, color.red, color.green, color.blue);
    std::string text(command);
    return text;
}
std::string terminal::setTextColorEsc(const RGB& color){
    return _setColorEsc(color, 38);
}
std::string terminal::setBackgroundColorEsc(const RGB& color){
    return _setColorEsc(color, 48);
}
std::string terminal::resetStylesEsc(){
    return "\033[0m";
}