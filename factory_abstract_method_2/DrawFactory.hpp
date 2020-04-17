#include "DrawFactoryShapes.hpp"
#include<map>

class DrawFactory {
std::map<Shape, std::unique_ptr<Factory> > mp;

public:
    DrawFactory() {
	mp[Shape::Square] = std::make_unique<SquareFactory>(); 
	mp[Shape::Circle] = std::make_unique<CircleFactory>(); 
	mp[Shape::Rectangle] = std::make_unique<RectangleFactory>(); 
    }  

    std::unique_ptr<Draw> make_pattern(const Shape& s) {
	auto _shape = mp[s]->fnDraw();
        _shape->make();
	return _shape;
    } 

}; 
