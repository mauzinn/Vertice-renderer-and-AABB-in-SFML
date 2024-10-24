#include <iostream>
#include <SFML\Graphics.hpp>

#include "./classes/hpp/body.hpp"
#include "./classes/hpp/collision.hpp"
#include "./classes/hpp/inputController.hpp"
#include "./classes/hpp/vector2.hpp"

int main() {
    InputController input;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Collisor display");
    sf::Event event;

    Vector2 square1_vertices[] = {
        Vector2(0, 0), Vector2(60, 0), Vector2(60, 60), Vector2(0, 60)
    };
    Body square1(square1_vertices, 4, Vector2(10, 10));

    Vector2 square2_vertices[] = {
        Vector2(0, 0), Vector2(100, 0), Vector2(100, 100), Vector2(0, 100)
    };
    Body square2(square2_vertices, 4, Vector2(200, 100));

    while(window.isOpen()) {
        window.clear();

        Body objects[] = {square1, square2};
        Collision objectsC(objects);

        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    input.keyDown();
                    break;

                case sf::Event::KeyReleased:
                    input.keyUp();
                    break;
            }
        }

        if (input.haveAnyKeyPressing) {
            Vector2 _new;
            _new.x = (input.isKeyPressing(sf::Keyboard::A) ? -2 : 0) + (input.isKeyPressing(sf::Keyboard::D) ? 2 : 0);
            _new.y = (input.isKeyPressing(sf::Keyboard::W) ? -2 : 0) + (input.isKeyPressing(sf::Keyboard::S) ? 2 : 0);

            square1.applyVector(_new);
        }

        for (int _b = 0; _b < 2; _b++) {
            Body _body = objects[_b];
            _body.isColliding = objectsC.isColliding(_body, objects[(_b % 2) + 1]);

            for (int _v = 0; _v < _body.size; _v++) {
                Vector2 _vertice = _body.vertices[_v];

                sf::CircleShape _point(float(2));
                _point.setFillColor(_body.isColliding ? sf::Color::Yellow : sf::Color::Red);
                _point.setPosition(sf::Vector2f(float(_vertice.x), float(_vertice.y)));

                window.draw(_point);
            }
        }

        window.display();
    }

    return 0;
}