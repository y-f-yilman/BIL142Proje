#ifndef GENERAL_H
#define GENERAL_H

#include <string>

class General {
public:
  General();
  static void printWithTypingEffect(const std::string &message,
                                    unsigned int milliseconds_per_char = 1);
  static std::string getUserInput(char i);
};

#endif // GENERAL_H
