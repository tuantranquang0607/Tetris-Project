#include "grid.h"
#include <iostream>
#include "colors.h"

// Define the constructor for the Grid class
Grid::Grid() {
    // Set the number of rows in the grid to 20
    numRows = 20;

    // Set the number of columns in the grid to 10
    numCols = 10;

    // Set the size of a cell to 30
    cellSize = 30;

    // Call the Initialize method to set up the grid
    Initialize();

    // Call the GetCellColors method to get the colors of the cells and store them in the colors vector
    colors = GetCellColors();
}

// Define the Initialize method to set up the grid
void Grid::Initialize() {
    // Loop through each row
    for(int row = 0; row < numRows; row++) {
        // Loop through each column in the current row
        for(int column = 0; column < numCols; column++) {
            // Set the value at the current row and column of the grid to 0
            grid[row][column] = 0;
        }
    }
}

// Define the Print method to display the grid
void Grid::Print() {
    // Loop through each row
    for(int row = 0; row < numRows; row++) {
        // Loop through each column in the current row
        for(int column = 0; column < numCols; column++) {
            // Print the value at the current row and column of the grid
            std::cout << grid[row][column] << " ";
        }
        // Print a newline character to move to the next row
        std::cout << std::endl;
    }
}

// Define the Draw method to render the grid
void Grid::Draw() {
    // Loop through each row
    for(int row = 0; row < numRows; row++) {
        // Loop through each column in the current row
        for(int column = 0; column < numCols; column++) {
            // Get the value at the current row and column of the grid
            int cellValue = grid[row][column];

            // Draw a rectangle at the current cell's position with the color corresponding to the cell's value
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int column) {
    if (row >= 0 && row < numRows && column >= 0 && column < numCols) {
        return false;
    }

    return true;
}


