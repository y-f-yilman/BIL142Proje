#ifndef GENERAL_H
#define GENERAL_H

#include <string>

class General {
public:
  General();
  static void printWithTypingEffect(const std::string &message,
                                    unsigned int milliseconds_per_char = 50);
  static std::string getUserInput();
};

#endif // GENERAL_H
