#include "../hpp/collision.hpp"
#include "../hpp/body.hpp"
#include "../hpp/vector2.hpp"

Collision::Collision(Body _bodies[]) {
    Collision::size = sizeof(Collision::bodies) / sizeof(Body);

    for (int _b = 0; _b < Collision::size; _b++) {
        Collision::bodies[_b] = _bodies[_b];
    }
}

bool Collision::isColliding(Body _body1, Body _body2) {
    Vector2 _body1_max, _body1_min, _body2_max, _body2_min;
    _body1_min = _body1.vertices[0];
    _body1_max = _body1.vertices[2];

    _body2_min = _body2.vertices[0];
    _body2_max = _body2.vertices[2];

    return (
        _body1_max.x > _body2_min.x && _body1_min.x < _body2_max.x &&
        _body1_max.y > _body2_min.y && _body1_min.y < _body2_max.y
    );
}