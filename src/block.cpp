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

// Function to move the block by a certain number of rows and columns
void Block::Move(int row, int column) {
    rowOffset += row; // Increase the row offset by the input row
    columnOffset += column; // Increase the column offset by the input column
};

// Function to get the positions of the cells in the block
std::vector<Position> Block::GetCellPosition() {
    std::vector<Position> tiles = cells[rotationState]; // Get the cells in the current rotation state
    std::vector<Position> moveTiles; // Vector to store the new positions of the cells

    // Loop through each cell in the block
    for (Position item : tiles) {
        // Create a new position for the cell by adding the row and column offsets
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);

        // Add the new position to the moveTiles vector
        moveTiles.push_back(newPos);
    }

    // Return the new positions of the cells
    return moveTiles;
}

// Function to rotate the block
void Block::Rotate() {
    // Increment the rotation state of the block
    rotationState ++;

    // If the rotation state exceeds the number of rotation states available, set it back to 0
    if (rotationState == (int)cells.size()) {
        rotationState = 0;
    }
}

// Function to prevent the rotation of the block outside the grid
void Block::UndoRotation() {
    // Decrement the rotation state of the block
    rotationState --;

    // If the rotation state is less than 0, set it to the last rotation state
    if (rotationState == -1) {
        rotationState = cells.size() - 1;
    }
};

