#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "linear_algebra.h"
#include "cube.hpp"

using namespace std;

sf::Color getRandomShadeOfYellow() {
    int r = 255 + rand() % 64 - 32;
    int g = 255 + rand() % 64 - 32;
    int b = rand() % 64 - 32;

    r = clamp(r, 0, 255);
    g = clamp(g, 0, 255);
    b = clamp(b, 0, 255);

    return sf::Color(r, g, b);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Cubes with Random Shades");

    std::vector<Cube> cubes;
    std::vector<sf::Color> colors;

    std::vector<Vec3> cubePositions = {
            Vec3(-50.0f, -50.0f, -50.0f),
            Vec3(50.0f, -50.0f, -50.0f),
            Vec3(-50.0f, 50.0f, -50.0f),
            Vec3(50.0f, 50.0f, -50.0f),
            Vec3(-50.0f, -50.0f, 50.0f),
            Vec3(50.0f, -50.0f, 50.0f),
            Vec3(-50.0f, 50.0f, 50.0f),
            Vec3(50.0f, 50.0f, 50.0f),
            Vec3(50.0f, 50.0f, 50.0f)
    };

    for (size_t i = 0; i < cubePositions.size(); ++i) {
        Cube cube = createCube(10.0f, cubePositions[i]);
        cubes.push_back(cube);

        sf::Color randomShade = getRandomShadeOfYellow();
        colors.push_back(randomShade);
    }

    bool dragging = false;
    sf::Vector2i lastMousePos;
    Mat3 rotation = Mat3();
    float zoom = 1.0f;
    float zoomSpeed = 0.1f;

    while (window.isOpen()) {
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

        window.clear(sf::Color(34, 47, 63));

        Mat3 zoomMatrix;
        zoomMatrix.mat[0][0] = zoom;
        zoomMatrix.mat[1][1] = zoom;
        zoomMatrix.mat[2][2] = zoom;

        std::vector<Cube> transformedCubes;
        for (const auto& cube : cubes) {
            Cube transformedCube = cube;
            transformVertices(rotation, transformedCube.vertices);
            transformVertices(zoomMatrix, transformedCube.vertices);
            transformedCubes.push_back(transformedCube);
        }

        for (size_t i = 0; i < transformedCubes.size(); ++i) {
            drawCube(window, transformedCubes[i], colors[i]);
        }

        window.display();
    }

    return 0;
}
