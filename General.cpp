#include "General.h"
#include <chrono> // For typing effect
#include <iostream>
#include <thread> // For typing effect

General::General() {}

std::string General::getUserInput(char i) {
  std::string input;
  std::cin >> input;
  return input;
}

void General::printWithTypingEffect(const std::string &message,
                                    unsigned int milliseconds_per_char) {
  for (char ch : message) {
    std::cout << ch << std::flush; // Output each character and flush the stream
    std::this_thread::sleep_for(
        std::chrono::milliseconds(milliseconds_per_char));
  }
  std::cout << std::endl; // End with a new line after the message is printed
}
