#include "block.h"

// Constructor for the Block class
Block::Block() {
    cellSize = 30; // Set the size of each cell in the block to 30
    rotationState = 0; // Initialize the rotation state of the block to 0
    colors = GetCellColors(); // Get the predefined colors for the cells
}

// Function to draw the block
void Block::Draw() {
    // Get the positions of the cells in the current rotation state
    std::vector<Position> tiles = cells[rotationState];

    // Loop through each cell in the block
    for (Position item : tiles) {
        // Draw a rectangle for each cell at the appropriate position and color
        // The '+1' and '-1' are for leaving a small gap between cells
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}
