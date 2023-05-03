#ifndef _TERMINAL_H_
#define _TERMINAL_H_ 1
#include "rgb.hpp"
#include <string>

namespace terminal {
    std::string setTextColorEsc(const RGB& color);
    std::string setBackgroundColorEsc(const RGB& color);
    std::string resetStylesEsc();
};

#endif