#include "../hpp/inputController.hpp"
#include <SFML\Window.hpp>

bool InputController::isKeyPressing(sf::Keyboard::Key key) {
    return sf::Keyboard::isKeyPressed(key);
}

void InputController::keyDown() {
    InputController::haveAnyKeyPressing = true;
}

void InputController::keyUp() {
    InputController::haveAnyKeyPressing = false;
}