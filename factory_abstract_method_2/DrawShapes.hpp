#include <iostream>

using namespace std;

enum class Shape {
    Square,
    Rectangle,
    Circle
};

class Draw {
public:
    virtual void make() = 0;
};

class Rectangle : public Draw {
public:
   void make() override {
	cout << "Draw Rectangle\n";
    }
};

class Square : public Draw {
public:
    void make() override {
	cout << "Draw square\n";
    }
};

class Circle : public Draw {
public:
    void make() override {
	cout << "Draw circle\n";
    }
};
