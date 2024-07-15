#include "cube.hpp"
using namespace std;


// THIS is the cube stuff that will be making ALL the cubes you see.
// with custom size and 6 edges to make a cube(you can add more to make it look cooler)
Cube createCube(float size, const Vec3& position) {
    Cube cube;

    cube.vertices = {
            Vec3(-size, -size, -size) + position, Vec3(size, -size, -size) + position,
            Vec3(size, size, -size) + position, Vec3(-size, size, -size) + position,
            Vec3(-size, -size, size) + position, Vec3(size, -size, size) + position,
            Vec3(size, size, size) + position, Vec3(-size, size, size) + position
    };

    cube.edges = {
            {0, 1}, {1, 2}, {2, 3}, {3, 0},
            {4, 5}, {5, 6}, {6, 7}, {7, 4},
            {0, 4}, {1, 5}, {2, 6}, {3, 7},
            {0, 2}, {1, 3}, {4, 6}, {5, 7},
            {0, 6}, {1, 7}, {2, 4}, {3, 5}
    };

    return cube;
}

/**
 * @brief transform the vertices of a cube using the given transformation matrix

 * @param mat the transformation matrix.
 * @param vertices list of vertices to be transformed
 */
void transformVertices(const Mat3& mat, vector<Vec3>& vertices) {
    for (auto& v : vertices) {
        v = mat * v;
    }
}

void drawCube(sf::RenderWindow& window, const Cube& cube, sf::Color color, const vector<Vec3>& transformedVertices) {
    sf::VertexArray lines(sf::Lines, cube.edges.size() * 2);
    const vector<Vec3>& vertices = (transformedVertices.empty() ? cube.vertices : transformedVertices);

    for (size_t i = 0; i < cube.edges.size(); ++i) {
        Vec3 v1 = vertices[cube.edges[i].first];
        Vec3 v2 = vertices[cube.edges[i].second];
        lines[i * 2].position = sf::Vector2f(v1.x + window.getSize().x / 2, v1.y + window.getSize().y / 2);
        lines[i * 2].color = color;
        lines[i * 2 + 1].position = sf::Vector2f(v2.x + window.getSize().x / 2, v2.y + window.getSize().y / 2);
        lines[i * 2 + 1].color = color;
    }
    window.draw(lines);
}