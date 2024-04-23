#pragma once

#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

// A class that represents a block of cells
class Block {
    public:
        Block(); // Constructor for the Block class
        void Draw(); // Function to draw the block
        int id; // Unique identifier for the block
        std::map<int, std::vector<Position>> cells; // Map to store the cells of the block in different rotation states

    private:
        int cellSize; // Size of each cell in the block
        int rotationState; // Current rotation state of the block
        std::vector<Color> colors; // Vector to store the colors of the cells
};
