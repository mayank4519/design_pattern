#include "DrawShapes.hpp"
#include <memory>

struct Factory {

    virtual std::unique_ptr<Draw> fnDraw() const = 0; 
};

struct SquareFactory : Factory {

     std::unique_ptr<Draw> fnDraw() const override {
	return make_unique<Square>();
     }
};
 
struct CircleFactory : Factory {

     std::unique_ptr<Draw> fnDraw() const override {
	return make_unique<Circle>();
     }
}; 

struct RectangleFactory : Factory {

     std::unique_ptr<Draw> fnDraw() const override {
	return make_unique<Rectangle>();
     }
}; 
