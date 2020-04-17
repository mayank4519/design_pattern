#include <iostream>
#include "Builder.hpp"

int main() {
  auto cb = CodeBuilder{"Person"}.add_field("Mayank", "string").add_field("26", "int");
  std::cout << cb;
}
