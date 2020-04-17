#include "Client.hpp"
#include "WeatherStation.hpp"

int main() {
  WeatherData weatherdata;
  Client one(1), two(2), three(3);
  weatherdata.addObserver(&one);
  weatherdata.addObserver(&two);
  weatherdata.addObserver(&three);

  weatherdata.setState(30.3, 5.6, 1.3);
  weatherdata.removeObserver(&one);
  weatherdata.setState(30.3, 5.6, 1.3);
}
