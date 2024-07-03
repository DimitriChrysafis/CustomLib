#include "camera.hpp"

Camera::Camera()
        : rotation(Mat3()), zoom(1.0f), zoomSpeed(0.1f), dragging(false), lastMousePos(0, 0) {}

void Camera::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                dragging = true;
                lastMousePos = sf::Mouse::getPosition(window);
            }
        }

        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                dragging = false;
            }
        }

        if (event.type == sf::Event::MouseMoved) {
            if (dragging) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2i delta = mousePos - lastMousePos;
                lastMousePos = mousePos;

                float angleX = delta.y * 0.01f;
                float angleY = delta.x * 0.01f;

                Mat3 rotX = Mat3::rotationMatrix(angleX, Vec3(1, 0, 0));
                Mat3 rotY = Mat3::rotationMatrix(angleY, Vec3(0, 1, 0));
                rotation = rotX * rotY * rotation;
            }
        }

        if (event.type == sf::Event::MouseWheelScrolled) {
            zoom += event.mouseWheelScroll.delta * zoomSpeed;
            if (zoom < 0.1f) zoom = 0.1f;
        }
    }
}

Mat3 Camera::getViewMatrix() const {
    Mat3 zoomMatrix;
    zoomMatrix.mat[0][0] = zoom;
    zoomMatrix.mat[1][1] = zoom;
    zoomMatrix.mat[2][2] = zoom;

    return zoomMatrix * rotation;
}
