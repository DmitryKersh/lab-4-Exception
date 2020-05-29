#include <bitset>
#include <exception>
#include <iostream>
#include <map>
#include <vector>

#include "MyException.h"

using std::cin;
using std::cout;
using std::endl;

struct A{
  int a1;
  float a2;
  virtual int get_2a1() { return  2 * a1; }
};

struct B{
  float b1, b2, b3;
};

class BadClass{
  int* numbers;

public:
  BadClass(){
    numbers = new int[10];
  }
};

class RAIIClass{
  int* numbers;

public:
  RAIIClass(){
    numbers = new int[10];
  }
  ~RAIIClass(){
    delete[] numbers;
  }

};

int main() {
    std::vector<int> vec{1, 2, 3};
    // std::out_of_range
    try {

      cout << vec.at(4);
    }
    catch (std::out_of_range& e) {
      cout << e.what() << endl;
    }

    // std::invalid_argument
    try {
      std::bitset<2>(17);
    }
    catch (std::invalid_argument& e) {
      cout << e.what() << endl;
    }

    //std::length_error
    try {
      vec.reserve(vec.max_size() + 1);
    }
    catch (std::length_error& e) {
      cout << e.what() << endl;
    }

    //std::bad_alloc
    try {
      long* huge_one = new long [111111111111111111];
    }
    catch (std::bad_alloc& e) {
      cout << e.what() << endl;
    }

    //std::bad_cast
    try {
      A struct1;
      A& ref1 = struct1;
      dynamic_cast<B&>(ref1);
    }
    catch (std::bad_cast& e){
      cout << e.what() << endl;
    }

    int a, b;
    cin >> a >> b;
    try {
      if (b == 0) throw MyException(-1, "Division on zero\n");
      cout << a << " / " << b << " = " << a / b << std::endl;
    }
    catch (MyException& e){
      cout << e.what() << endl;
    }

    //example how class without RAII can cause memory leaks
    try{
      BadClass item;
      throw 1;
    }
    catch (...){
      cout << "fooooo!";
    }

    //example of class with RAII working normally

  try{
    RAIIClass item;
    throw 1;
  }
  catch (...){
    cout << "fine!";
  }

  return 0;
}

