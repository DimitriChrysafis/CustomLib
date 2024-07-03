#ifndef COLORS_HPP
#define COLORS_HPP

#include <SFML/Graphics.hpp>
#include <cstdlib>

// Function to generate a random shade of yellow
sf::Color getRandomShadeOfYellow() {
    int r = 255 + rand() % 64 - 32;
    int g = 255 + rand() % 64 - 32;
    int b = rand() % 64 - 32;

    r = std::clamp(r, 0, 255);
    g = std::clamp(g, 0, 255);
    b = std::clamp(b, 0, 255);

    return sf::Color(r, g, b);
}

// Function to generate a random shade of red
sf::Color getRandomShadeOfRed() {
    int r = 255 + rand() % 64 - 32;
    int g = rand() % 64 - 32;
    int b = rand() % 64 - 32;

    r = std::clamp(r, 0, 255);
    g = std::clamp(g, 0, 255);
    b = std::clamp(b, 0, 255);

    return sf::Color(r, g, b);
}

// Function to generate a random shade of green
sf::Color getRandomShadeOfGreen() {
    int r = rand() % 64 - 32;
    int g = 255 + rand() % 64 - 32;
    int b = rand() % 64 - 32;

    r = std::clamp(r, 0, 255);
    g = std::clamp(g, 0, 255);
    b = std::clamp(b, 0, 255);

    return sf::Color(r, g, b);
}

// Function to generate a random shade of blue
sf::Color getRandomShadeOfBlue() {
    int r = rand() % 64 - 32;
    int g = rand() % 64 - 32;
    int b = 255 + rand() % 64 - 32;

    r = std::clamp(r, 0, 255);
    g = std::clamp(g, 0, 255);
    b = std::clamp(b, 0, 255);

    return sf::Color(r, g, b);
}

// Function to generate a random shade of purple
sf::Color getRandomShadeOfPurple() {
    int r = 255 + rand() % 64 - 32;
    int g = rand() % 64 - 32;
    int b = 255 + rand() % 64 - 32;

    r = std::clamp(r, 0, 255);
    g = std::clamp(g, 0, 255);
    b = std::clamp(b, 0, 255);

    return sf::Color(r, g, b);
}

// Function to generate a random shade of cyan
sf::Color getRandomShadeOfCyan() {
    int r = rand() % 64 - 32;
    int g = 255 + rand() % 64 - 32;
    int b = 255 + rand() % 64 - 32;

    r = std::clamp(r, 0, 255);
    g = std::clamp(g, 0, 255);
    b = std::clamp(b, 0, 255);

    return sf::Color(r, g, b);
}

// Function to generate a random shade of orange
sf::Color getRandomShadeOfOrange() {
    int r = 255 + rand() % 64 - 32;
    int g = 165 + rand() % 64 - 32;
    int b = rand() % 64 - 32;

    r = std::clamp(r, 0, 255);
    g = std::clamp(g, 0, 255);
    b = std::clamp(b, 0, 255);

    return sf::Color(r, g, b);
}

// Function to generate a random shade of pink
sf::Color getRandomShadeOfPink() {
    int r = 255 + rand() % 64 - 32;
    int g = 192 + rand() % 64 - 32;
    int b = 203 + rand() % 64 - 32;

    r = std::clamp(r, 0, 255);
    g = std::clamp(g, 0, 255);
    b = std::clamp(b, 0, 255);

    return sf::Color(r, g, b);
}

// Function to generate a random shade of gray
sf::Color getRandomShadeOfGray() {
    int gray = 128 + rand() % 64 - 32;

    gray = std::clamp(gray, 0, 255);

    return sf::Color(gray, gray, gray);
}

// Function to generate a random shade of brown
sf::Color getRandomShadeOfBrown() {
    int r = 139 + rand() % 64 - 32;
    int g = 69 + rand() % 64 - 32;
    int b = 19 + rand() % 64 - 32;

    r = std::clamp(r, 0, 255);
    g = std::clamp(g, 0, 255);
    b = std::clamp(b, 0, 255);

    return sf::Color(r, g, b);
}

#endif // COLORS_HPP
