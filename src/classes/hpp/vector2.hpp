#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>

class Vector2 {
    public:
    int x, y;

    Vector2(int _x = 0, int _y = 0);

    void applyVector(Vector2 _position);
    void print();
};

#endif