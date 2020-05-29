//
// Created by User on 17.04.2020.
//

#ifndef LAB_ORIG_4_MYEXCEPTION_H
#define LAB_ORIG_4_MYEXCEPTION_H

#include <exception>
#include <string>

class MyException : virtual public std::exception {
protected:
  std::string message;
  int number;

public:
  MyException (int num, const std::string& msg) noexcept {
    number = num;
    message = msg;
  }
  ~MyException() noexcept override = default;

  const char* what()  const noexcept override {
    return message.c_str();
  }
  int getErrorNumber() const noexcept {
    return number;
  }
};

#endif // LAB_ORIG_4_MYEXCEPTION_H
