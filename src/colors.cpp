#include "colors.h"

// Define a Color structure with 4 components: red, green, blue, and alpha (transparency)
const Color darkGray = {26, 32, 40, 255};
const Color green = {47, 230, 23, 255};
const Color red = {232, 18, 218, 255};
const Color orange = {226, 116, 17, 255};
const Color yellow = {237, 234, 4, 255};
const Color purple = {166, 0, 247, 255};
const Color cyan = {21, 204, 209, 255};
const Color blue = {13, 64, 216, 255};

// Function to return a vector of predefined colors
std::vector<Color> GetCellColors() {
    // Return a vector containing all the predefined colors
    return {darkGray, green, red, orange, yellow, purple, cyan, blue};
}