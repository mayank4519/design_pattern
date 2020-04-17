#include "HotDrinkFactory.hpp"
#include <map>

using namespace std;

class DrinkFactory {
    map<string , unique_ptr<HotDrinkFactory> > hot_factories;

public:
    DrinkFactory() {
	hot_factories["tea"] = make_unique<TeaFactory>();
	hot_factories["coffee"] = make_unique<CoffeeFactory>();
    }

    std::unique_ptr<HotDrink> make_drink(const string& drink) {
	auto hot_drink =  hot_factories[drink]->make();
	hot_drink->prepare(200);
	return hot_drink;
    } 
};
