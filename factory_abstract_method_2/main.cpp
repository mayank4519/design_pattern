#include "DrawFactory.hpp"

int main() {
   DrawFactory d;
   auto c = d.make_pattern(Shape::Square); 
   return 0;
}
