#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <vector>
#include "linear_algebra.h"
#include "cube.hpp"
#include "utils.hpp"


std::vector<Cube> createPyramidWithLines(float baseSize, float height, float cubeSize, const Vec3& offset = Vec3(0.0f, 0.0f, 0.0f)) {
    std::vector<Cube> cubes;


    Vec3 v0(-baseSize / 2.0f, 0.0f, -baseSize / 2.0f);
    Vec3 v1(baseSize / 2.0f, 0.0f, -baseSize / 2.0f);
    Vec3 v2(baseSize / 2.0f, 0.0f, baseSize / 2.0f);
    Vec3 v3(-baseSize / 2.0f, 0.0f, baseSize / 2.0f);
    Vec3 v4(0.0f, height, 0.0f);

    // Offset all vertices by the provided offset
    v0 += offset;
    v1 += offset;
    v2 += offset;
    v3 += offset;
    v4 += offset;


    std::vector<std::pair<int, int>> baseEdges = {
            {0, 1}, {1, 2}, {2, 3}, {3, 0}
    };


    std::vector<std::pair<int, int>> apexEdges = {
            {0, 4}, {1, 4}, {2, 4}, {3, 4}
    };

    // Create cubes along base edges
    for (const auto& edge : baseEdges) {
        Vec3 start = (edge.first == 0) ? v0 : (edge.first == 1) ? v1 : (edge.first == 2) ? v2 : v3;
        Vec3 end = (edge.second == 0) ? v0 : (edge.second == 1) ? v1 : (edge.second == 2) ? v2 : v3;
        std::vector<Cube> edgeCubes = drawLineOfCubes(start, end, cubeSize);
        cubes.insert(cubes.end(), edgeCubes.begin(), edgeCubes.end());
    }

    // Create cubes along edges from base to apex
    for (const auto& edge : apexEdges) {
        Vec3 start = (edge.first == 0) ? v0 : (edge.first == 1) ? v1 : (edge.first == 2) ? v2 : v3;
        Vec3 end = v4;
        std::vector<Cube> edgeCubes = drawLineOfCubes(start, end, cubeSize);
        cubes.insert(cubes.end(), edgeCubes.begin(), edgeCubes.end());
    }

    return cubes;
}

#endif // SHAPES_HPP
