#include "../hpp/vector2.hpp"
#include <iostream>

Vector2::Vector2(int _x, int _y) {
    Vector2::x = _x;
    Vector2::y = _y;
}

void Vector2::applyVector(Vector2 _position) {
    Vector2::x += _position.x;
    Vector2::y += _position.y;
}

void Vector2::print() {
    std::cout << "{ X:" << Vector2::x << ", Y: " << Vector2::y << " }\n";
}