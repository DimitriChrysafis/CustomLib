#include "camera.hpp"
using namespace std;
using namespace sf;

/**
 * @brief default constructor for the Camera class.
 *
 * starts the camera with a default rotation matrix, zoom level, zoom speed, dragging state, and the last mouse position.
 */
Camera::Camera()
        : rotation(Mat3()), zoom(1.0f), zoomSpeed(0.1f), dragging(false), lastMousePos(0, 0) {}

void Camera::handleEvents(RenderWindow& window) {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed)
            window.close();

        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == Mouse::Left) {
                dragging = true;
                lastMousePos = Mouse::getPosition(window);
            }
        }

        if (event.type == Event::MouseButtonReleased) {
            if (event.mouseButton.button == Mouse::Left) {
                dragging = false;
            }
        }

        if (event.type == Event::MouseMoved) {
            if (dragging) {
                Vector2i mousePos = Mouse::getPosition(window);
                Vector2i delta = mousePos - lastMousePos;
                lastMousePos = mousePos;

                float angleX = delta.y * 0.01f;
                float angleY = delta.x * 0.01f;

                Mat3 rotX = Mat3::rotationMatrix(angleX, Vec3(1, 0, 0));
                Mat3 rotY = Mat3::rotationMatrix(angleY, Vec3(0, 1, 0));
                rotation = rotX * rotY * rotation;
            }
        }

        if (event.type == Event::MouseWheelScrolled) {
            zoom += event.mouseWheelScroll.delta * zoomSpeed;
            if (zoom < 0.1f) zoom = 0.1f;
        }
    }
}


/**
 * @brief returns the view matrix for the camera.
 * @brief returns the view matrix for the camera.
 *
 * the view thing is just made by combining the zoom matrix and the rotation matrix.
 *
 * @return The view matrix as a Mat3 object.
 */
Mat3 Camera::getViewMatrix() const {
    Mat3 zoomMatrix;
    zoomMatrix.mat[0][0] = zoom;
    zoomMatrix.mat[1][1] = zoom;
    zoomMatrix.mat[2][2] = zoom;

    return zoomMatrix * rotation;
}
