#pragma once

class Observer {
public:
  virtual void update(float temp, float pressure, float humidity) const = 0;
};
