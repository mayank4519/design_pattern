#include "DrinkFactory.hpp"
#include <iostream>
#include <string>
using namespace std;

//To avoid below situations where multiple if's ar required to fullfill the requirement.
//And to provide factory like design, meaning provide support for all kind of methods, factory design method is used.
//Factory method is a creational design pattern
/*The Factory Method pattern is a design pattern used to define a runtime interface for creating an object. 
  It’s called a factory because it creates various types of objects without necessarily knowing what kind 
  of object it creates or how to create it.
*/

/*unique_ptr<HotDrink> make_drink(string type) {
    unique_ptr<HotDrink> drink;
    if ( type == "tea") {
	drink = make_unique<Tea>();	
	drink->prepare(300);
    }
    if ( type == "coffee") {
	drink = make_unique<Coffee>();	
	drink->prepare(300);
    }
    return drink;
}*/

int main() {
    DrinkFactory d;
    auto c = d.make_drink("coffee");
    return 0;
};
