#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "linear_algebra.h"
#include "cube.hpp"
#include "camera.hpp"
#include "render.hpp"
#include "colors.hpp"
#include "shapes.hpp"

using namespace std;
using namespace sf;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    RenderWindow window(VideoMode(800, 600), "Pyramid with Lines");

    vector<Cube> cubes;
    vector<Color> colors;

    // SAMPLE: pyramid with Lines
    float baseSize = 200.0f;
    float height = 300.0f;
    float cubeSize = 10.0f;
    Vec3 pyramidOffset(0.0f, 0.0f, 0.0f);

    cubes = createPyramidWithLines(baseSize, height, cubeSize, pyramidOffset);

    // Assign random colors to the cubes for variety
    for (size_t i = 0; i < cubes.size(); ++i) {
        Color randomColor = getRandomShadeOfBrown();
        colors.push_back(randomColor);
    }

    Camera camera;

    while (window.isOpen()) {
        camera.handleEvents(window);

        window.clear(Color(34, 47, 63));

        renderCubes(window, cubes, colors, camera);

        window.display();
    }

    return 0;
}
