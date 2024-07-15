#ifndef COLORS_HPP
#define COLORS_HPP

#include <SFML/Graphics.hpp>
#include <cstdlib>

// ALL COLORS

using namespace std;
using namespace sf;

// Function to generate a random shade of yellow
Color getRandomShadeOfYellow() {
    int r = 255 + rand() % 64 - 32;
    int g = 255 + rand() % 64 - 32;
    int b = rand() % 64 - 32;

    r = clamp(r, 0, 255);
    g = clamp(g, 0, 255);
    b = clamp(b, 0, 255);

    return Color(r, g, b);
}

// Function to generate a random shade of red
Color getRandomShadeOfRed() {
    int r = 255 + rand() % 64 - 32;
    int g = rand() % 64 - 32;
    int b = rand() % 64 - 32;

    r = clamp(r, 0, 255);
    g = clamp(g, 0, 255);
    b = clamp(b, 0, 255);

    return Color(r, g, b);
}

// Function to generate a random shade of green
Color getRandomShadeOfGreen() {
    int r = rand() % 64 - 32;
    int g = 255 + rand() % 64 - 32;
    int b = rand() % 64 - 32;

    r = clamp(r, 0, 255);
    g = clamp(g, 0, 255);
    b = clamp(b, 0, 255);

    return Color(r, g, b);
}

// Function to generate a random shade of blue
Color getRandomShadeOfBlue() {
    int r = rand() % 64 - 32;
    int g = rand() % 64 - 32;
    int b = 255 + rand() % 64 - 32;

    r = clamp(r, 0, 255);
    g = clamp(g, 0, 255);
    b = clamp(b, 0, 255);

    return Color(r, g, b);
}

// Function to generate a random shade of purple
Color getRandomShadeOfPurple() {
    int r = 255 + rand() % 64 - 32;
    int g = rand() % 64 - 32;
    int b = 255 + rand() % 64 - 32;

    r = clamp(r, 0, 255);
    g = clamp(g, 0, 255);
    b = clamp(b, 0, 255);

    return Color(r, g, b);
}

// Function to generate a random shade of cyan
Color getRandomShadeOfCyan() {
    int r = rand() % 64 - 32;
    int g = 255 + rand() % 64 - 32;
    int b = 255 + rand() % 64 - 32;

    r = clamp(r, 0, 255);
    g = clamp(g, 0, 255);
    b = clamp(b, 0, 255);

    return Color(r, g, b);
}

// Function to generate a random shade of orange
Color getRandomShadeOfOrange() {
    int r = 255 + rand() % 64 - 32;
    int g = 165 + rand() % 64 - 32;
    int b = rand() % 64 - 32;

    r = clamp(r, 0, 255);
    g = clamp(g, 0, 255);
    b = clamp(b, 0, 255);

    return Color(r, g, b);
}

// Function to generate a random shade of pink
Color getRandomShadeOfPink() {
    int r = 255 + rand() % 64 - 32;
    int g = 192 + rand() % 64 - 32;
    int b = 203 + rand() % 64 - 32;

    r = clamp(r, 0, 255);
    g = clamp(g, 0, 255);
    b = clamp(b, 0, 255);

    return Color(r, g, b);
}

// Function to generate a random shade of gray
Color getRandomShadeOfGray() {
    int gray = 128 + rand() % 64 - 32;

    gray = clamp(gray, 0, 255);

    return Color(gray, gray, gray);
}

// Function to generate a random shade of brown
Color getRandomShadeOfBrown() {
    int r = 139 + rand() % 64 - 32;
    int g = 69 + rand() % 64 - 32;
    int b = 19 + rand() % 64 - 32;

    r = clamp(r, 0, 255);
    g = clamp(g, 0, 255);
    b = clamp(b, 0, 255);

    return Color(r, g, b);
}

#endif
