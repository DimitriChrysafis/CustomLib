#include "utils.hpp"
using namespace std;

vector<Cube> drawLineOfCubes(const Vec3& start, const Vec3& end, float cubeSize) {
    vector<Cube> cubes;

    Vec3 direction = end - start;
    float length = direction.length();
    int numCubes = static_cast<int>(length / cubeSize);

    // Unit direction vector (do not ask me what this is)
    Vec3 unitDir = direction.normalize();

    for (int i = 0; i < numCubes; ++i) {
        Vec3 position = start + unitDir * (i * cubeSize);
        Cube cube(cubeSize, position);
        cubes.push_back(cube);
    }

    return cubes;
}
