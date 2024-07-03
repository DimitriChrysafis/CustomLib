#ifndef CUBE_HPP
#define CUBE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "linear_algebra.h"

struct Cube {
    std::vector<Vec3> vertices;
    std::vector<std::pair<int, int>> edges;
};

Cube createCube(float size, const Vec3& position);

void transformVertices(const Mat3& mat, std::vector<Vec3>& vertices);

void drawCube(sf::RenderWindow& window, const Cube& cube, sf::Color color, const std::vector<Vec3>& transformedVertices = {});

#endif
