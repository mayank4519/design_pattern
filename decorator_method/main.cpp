#include <Decorator.hpp>

int main() {
 Flower *rose = new Rose();
 std::cout << rose->str() << "\n";
 Flower *lily = new Lily();
 std::cout << lily->str() << "\n";

 Flower *rosedecorator = new RedFlower(rose);
 std::cout << rosedecorator->str() << "\n";
 Flower *lilydecorator = new BlueFlower(lily);
 std::cout << lilydecorator->str() << "\n";
}

