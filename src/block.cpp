#include "block.h"

// Constructor for the Block class
Block::Block() {
    cellSize = 30; // Set the size of each cell in the block to 30
    rotationState = 0; // Initialize the rotation state of the block to 0
    colors = GetCellColors(); // Get the predefined colors for the cells
    columnOffset = 0; // Initialize the column offset to 0
    rowOffset = 0; // Initialize the row offset to 0
}

// Function to draw the block
void Block::Draw() {
    // Get the positions of the cells in the block
    std::vector<Position> tiles = GetCellPosition();

    // Loop through each cell in the block
    for (Position item : tiles) {
        // Draw a rectangle for each cell at the appropriate position and color
        // The '+1' and '-1' are for leaving a small gap between cells
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int row, int column) {
    rowOffset += row;
    columnOffset += column;
};

std::vector<Position> Block::GetCellPosition() {
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> moveTiles;

    for (Position item : tiles) {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);

        moveTiles.push_back(newPos);
    }

    return moveTiles;
};