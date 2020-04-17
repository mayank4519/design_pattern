#pragma once
#include <vector>
#include <algorithm>

class WeatherData {
 vector<Observer*> observers;
 float temp, pressure, humidity;

public:
 void addObserver(Observer *observer) {
   observers.push_back(observer);
 } 
 void removeObserver(Observer *observer) {
   auto iterator = std::find(observers.begin(), observers.end(), observer);
   if(iterator != observers.end())
     observers.erase(iterator);
 } 

 void notifyObserver() {
   for(auto observer : observers) {
     observer->update(temp, pressure, humidity);
   }
 }
 void setState(float temp, float pressure, float humidity) 
 {
   this->temp = temp;
   this->pressure = pressure;
   this->humidity = humidity;
   notifyObserver(); 
 }
};
