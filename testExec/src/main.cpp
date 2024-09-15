#include "jthread.h"
#include <iostream>
#include <memory>

int main() {
  slib::jthread jt{[](auto &&...) { std::cout << "Hello from a thread\n"; }};
}