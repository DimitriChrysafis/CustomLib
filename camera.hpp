#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>
#include "linear_algebra.h"

class Camera {
public:
    Camera();

    void handleEvents(sf::RenderWindow& window);
    Mat3 getViewMatrix() const;

private:
    Mat3 rotation;
    float zoom;
    float zoomSpeed;
    bool dragging;
    sf::Vector2i lastMousePos;
};

#endif
