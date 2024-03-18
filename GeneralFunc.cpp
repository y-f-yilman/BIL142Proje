//
// Created by o_ark on 18.03.2024.
//

#include "GeneralFunc.h"

#include <chrono>
#include <iostream>
#include <thread>

GeneralFunc::GeneralFunc() = default;

int GeneralFunc::getUserInput() {
    int input;
    std::cin >> input;
    return input;
}

std::string GeneralFunc::getUserInput(char i) {
    std::string input;
    std::cin >> input;
    return input;
}


void GeneralFunc::printWithTypingEffect(const std::string &message, unsigned int milliseconds_per_char) {
    for (char ch : message){
        std::cout << ch << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds_per_char));
    }
    std::cout << std::endl;
}
