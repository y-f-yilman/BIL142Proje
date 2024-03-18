//
// Created by o_ark on 18.03.2024.
//

#ifndef SPACEADVENTURE_GENERALFUNC_H
#define SPACEADVENTURE_GENERALFUNC_H

#include <string>

class GeneralFunc {
public:
    GeneralFunc();
    static void printWithTypingEffect(const std::string &message,unsigned int milliseconds_per_char = 30);
    static int getUserInput();
    static std::string getUserInput(char i);
};

#endif //SPACEADVENTURE_GENERALFUNC_H
