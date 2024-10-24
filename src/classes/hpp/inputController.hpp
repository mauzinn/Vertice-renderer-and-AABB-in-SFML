#ifndef INPUTCONTROLLER_HPP
#define INPUTCONTROLLER_HPP

#include "SFML\Window.hpp"

class InputController {
    public:
    bool isKeyPressing(sf::Keyboard::Key key);

    bool haveAnyKeyPressing;
    void keyDown();
    void keyUp();
};

#endif