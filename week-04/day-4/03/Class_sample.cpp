#include <iostream>
#include <string>

//--> shape.hpp
class Shape {
	private:
		float mWidth;
		float mHeight;
	protected:
		float mArea; //In order to be able to reach this from the virtual functions for calcuateArea()
		virtual void calculateArea()=0;
	public:
		Shape(float _w, float _h);
		void setWidth(float _width);
		void setHeight(float _height);
		float getWidth();
		float getHeight();
		float getArea();
		virtual std::string getName()=0;
		virtual ~Shape(); //This is virtual, so the child classes can override this and create their own destructors.
 };

//--> shape.cpp
Shape::Shape(float _w, float _h) {
	this->mWidth = _w;
	this->mHeight = _h;
}

Shape::~Shape() {
//Nothing to do.
}

void Shape::setWidth(float _width) {
	this->mWidth = _width;
	this->calculateArea(); //This makes sure, that whenever I update the width or the height, the area gets recalculated.
}

void Shape::setHeight(float _height) {
	this->mHeight = _height;
	this->calculateArea(); //This makes sure, that whenever I update the width or the height, the area gets recalculated.
}

float Shape::getWidth() {
	return this->mWidth;
}

float Shape::getHeight() {
	return this->mHeight;
}

float Shape::getArea() {
	return this->mArea;
}


//--> Triangle.hpp

class Triangle: public Shape {
	protected:
		virtual void calculateArea();
	public:
		Triangle(float _w, float _h);
		virtual std::string getName();
		virtual ~Triangle();
};

//--> Triangle.cpp

Triangle::Triangle(float _w, float _h) : Shape(_w, _h) {  //This is how I can leave it up to the Parent class to actually do their part in constructing the instance.
	this->calculateArea();
}

Triangle::~Triangle() {
//nothing to do here
}

void Triangle::calculateArea() {
        this->mArea = this->getWidth() * this->getHeight() / 2;
}

std::string Triangle::getName() {
	return std::string("Triangle");
}

//-->Square.hpp
class Square: public Shape {
        protected:
                virtual void calculateArea();
        public:
                Square(float _w, float _h);
                virtual std::string getName();
                virtual ~Square();
};

//--> Square.cpp

Square::Square(float _w, float _h) : Shape(_w, _h) {
        this->calculateArea();
}

Square::~Square() {
//nothing to do here
}

void Square::calculateArea() {
        this->mArea = this->getWidth() * this->getHeight();
}

std::string Square::getName() {
        return std::string("Square");
}

//--> main.cpp

int main(int argc, char** argv) {
	Shape* a = new Triangle(12.34, 34.2);
	Shape* b = new Square(12.34, 54.3);
	std::cout << "I'm a " << a->getName() << " and I'm " << a->getArea() << " big." << std::endl;
	std::cout << "I'm a " << b->getName() << " and I'm " << b->getArea() << " big." << std::endl;
	b->setWidth(2.0);
	std::cout << "I'm a " << b->getName() << " and I'm " << b->getArea() << " big." << std::endl;
	b->setHeight(3.0);
	std::cout << "I'm a " << b->getName() << " and I'm " << b->getArea() << " big." << std::endl;
}
