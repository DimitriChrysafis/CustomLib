#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <vector>
#include "linear_algebra.h"
#include "cube.hpp"
#include "utils.hpp"

using namespace std; 
/*
 * IMPORTANT READ MEEEEE
 *you can make any shape you want here (see readMe for demo) its super sick and it can be used to make solar systems ect
 */

vector<Cube> createPyramidWithLines(float baseSize, float height, float cubeSize, const Vec3& offset = Vec3(0.0f, 0.0f, 0.0f)) {
    vector<Cube> cubes;


    Vec3 v0(-baseSize / 2.0f, 0.0f, -baseSize / 2.0f);
    Vec3 v1(baseSize / 2.0f, 0.0f, -baseSize / 2.0f);
    Vec3 v2(baseSize / 2.0f, 0.0f, baseSize / 2.0f);
    Vec3 v3(-baseSize / 2.0f, 0.0f, baseSize / 2.0f);
    Vec3 v4(0.0f, height, 0.0f);

    // offset all vertices by the provided offset (if u want more than 1 shape)
    v0 += offset;
    v1 += offset;
    v2 += offset;
    v3 += offset;
    v4 += offset;


    vector<pair<int, int>> baseEdges = {
            {0, 1}, {1, 2}, {2, 3}, {3, 0}
    };


    vector<pair<int, int>> apexEdges = {
            {0, 4}, {1, 4}, {2, 4}, {3, 4}
    };

    // Create cubes along base edges
    for (const auto& edge : baseEdges) {
        Vec3 start = (edge.first == 0) ? v0 : (edge.first == 1) ? v1 : (edge.first == 2) ? v2 : v3;
        Vec3 end = (edge.second == 0) ? v0 : (edge.second == 1) ? v1 : (edge.second == 2) ? v2 : v3;
        vector<Cube> edgeCubes = drawLineOfCubes(start, end, cubeSize);
        cubes.insert(cubes.end(), edgeCubes.begin(), edgeCubes.end());
    }

    // Create cubes along edges from base to apex
    for (const auto& edge : apexEdges) {
        Vec3 start = (edge.first == 0) ? v0 : (edge.first == 1) ? v1 : (edge.first == 2) ? v2 : v3;
        Vec3 end = v4;
        vector<Cube> edgeCubes = drawLineOfCubes(start, end, cubeSize);
        cubes.insert(cubes.end(), edgeCubes.begin(), edgeCubes.end());
    }

    return cubes;
}

#endif 
