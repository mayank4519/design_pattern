#pragma once
#include <iostream>
#include "Observer.hpp"
using namespace std;

class Client : public Observer {
 int m_id;
public:
 Client(int id) 
 : m_id(id)
 {}

 void update(float temp, float pressure, float humidity) const override {
   cout << "CLIENT ID: " << m_id << "\n";
   cout << "Temp is " << temp << "\n";   
   cout << "Pressure is " << pressure << "\n";
   cout << "Humidity is " << humidity << "\n\n";  
 } 
};
