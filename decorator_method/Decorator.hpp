#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//Component
class Flower {
public:
  virtual string str() const  = 0;
};
//CONCRETE COMPONENT
class Rose : public Flower {
public:
  string str() const {
    ostringstream oss;
    oss << "Flower is Rose";
    return oss.str();
  }
};

//CONCRETE COMPONENT
class Lily : public Flower {
public:
  string str() const {
    ostringstream oss;
    oss << "Flower is Lily";
    return oss.str();
  }
};

//DECORATOR
class FlowerDecorator : public Flower {
protected:
  Flower *flower;
public:
  FlowerDecorator(Flower *flower)
  : flower(flower)
  {}
  string str() const {
    return flower->str();
  } 
};

//CONCRETE DECORATOR
class RedFlower : public FlowerDecorator {
public:
  RedFlower(Flower* flower)
  : FlowerDecorator(flower)
  {}
  string str() const {
    ostringstream oss;
    oss << flower->str() << " and red.";
    return oss.str();
  }
};

//CONCRETE DECORATOR
class BlueFlower : public FlowerDecorator {
public:
  BlueFlower(Flower* flower)
  : FlowerDecorator(flower)
  {}
  string str() const {
    ostringstream oss;
    oss << flower->str() << " and blue.";
    return oss.str();
  }
};



