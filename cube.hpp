#ifndef CUBE_HPP
#define CUBE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "linear_algebra.h"

using namespace std;

struct Cube {
    vector<Vec3> vertices;
    vector<pair<int, int>> edges;

    Cube(float size = 1.0f, const Vec3& pos = Vec3()) {
        float halfSize = size / 2.0f;

        vertices = {
                Vec3(-halfSize, -halfSize, -halfSize) + pos,
                Vec3(halfSize, -halfSize, -halfSize) + pos,
                Vec3(halfSize, halfSize, -halfSize) + pos,
                Vec3(-halfSize, halfSize, -halfSize) + pos,
                Vec3(-halfSize, -halfSize, halfSize) + pos,
                Vec3(halfSize, -halfSize, halfSize) + pos,
                Vec3(halfSize, halfSize, halfSize) + pos,
                Vec3(-halfSize, halfSize, halfSize) + pos
        };

        edges = {
                {0, 1}, {1, 2}, {2, 3}, {3, 0},
                {4, 5}, {5, 6}, {6, 7}, {7, 4},
                {0, 4}, {1, 5}, {2, 6}, {3, 7}
        };
    }
};

Cube createCube(float size, const Vec3& position);

void transformVertices(const Mat3& mat, vector<Vec3>& vertices);

void drawCube(sf::RenderWindow& window, const Cube& cube, sf::Color color, const vector<Vec3>& transformedVertices = {});

#endif
