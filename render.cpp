#include "render.hpp"

void renderCubes(sf::RenderWindow& window, const std::vector<Cube>& cubes, const std::vector<sf::Color>& colors, const Camera& camera) {
    std::vector<Cube> transformedCubes;

    // Transform cubes according to camera view
    for (const auto& cube : cubes) {
        Cube transformedCube = cube;
        transformVertices(camera.getViewMatrix(), transformedCube.vertices);
        transformedCubes.push_back(transformedCube);
    }

    // Render transformed cubes
    for (size_t i = 0; i < transformedCubes.size(); ++i) {
        drawCube(window, transformedCubes[i], colors[i]);
    }
}
