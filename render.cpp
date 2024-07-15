#include "render.hpp"

using namespace std;

void renderCubes(sf::RenderWindow& window, const vector<Cube>& cubes, const vector<sf::Color>& colors, const Camera& camera) {
    vector<Cube> transformedCubes;

    // TRANSFORM THE CUBES GIVEN THE CAMERA VIEW
    for (const auto& cube : cubes) {
        Cube transformedCube = cube;
        transformVertices(camera.getViewMatrix(), transformedCube.vertices);
        transformedCubes.push_back(transformedCube);
    }

    // iterate and render each cube
    for (size_t i = 0; i < transformedCubes.size(); ++i) {
        drawCube(window, transformedCubes[i], colors[i]);
    }
}
