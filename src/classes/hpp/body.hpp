#ifndef BODY_HPP
#define BODY_HPP

#include "./vector2.hpp"

class Body {
    public:
    bool isColliding = false;
    Vector2 position;
    Vector2 vertices[4];
    int size;

    Body(Vector2 _vertices[] = 0, int _size = 0, Vector2 _position = 0);

    void applyVector(Vector2 _position);
};

#endif