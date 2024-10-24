#include "../hpp/body.hpp"
#include "../hpp/vector2.hpp"

void Body::applyVector(Vector2 _position) {
    Body::position = _position;
    for (int _v = 0; _v < Body::size; _v++) {
        Body::vertices[_v].applyVector(_position);
    }
}

Body::Body(Vector2 _vertices[], int _size, Vector2 _position) {
    Body::size = _size;
    for (int _v = 0; _v < _size; _v++) {
        Body::vertices[_v].x = _vertices[_v].x;
        Body::vertices[_v].y = _vertices[_v].y;
    }
    Body::applyVector(_position);
}