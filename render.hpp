#ifndef RENDER_HPP
#define RENDER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "cube.hpp"
#include "camera.hpp"

void renderCubes(sf::RenderWindow& window, const std::vector<Cube>& cubes, const std::vector<sf::Color>& colors, const Camera& camera);
// :(
#endif
