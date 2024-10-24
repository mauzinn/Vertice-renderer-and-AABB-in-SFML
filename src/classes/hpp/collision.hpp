#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "./body.hpp"

class Collision {
    private:
    Body bodies[2];
    int size;

    public:
    Collision(Body _bodies[]);

    bool isColliding(Body _body1, Body _body2);
};

#endif