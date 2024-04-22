// Include the Grid class header file and the iostream library for console output
#include "grid.h"
#include <iostream>

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

    // Call the getCellColors method to get the colors of the cells and store them in the colors vector
    colors = getCellColors();
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

// Define the getCellColors method to get the colors of the cells
std::vector<Color> Grid::getCellColors() {
    // Define some Color variables
    Color darkGray = {26, 32, 40, 255};
    Color green = {47, 230, 23, 255};
    Color red = {232, 18, 218, 255};
    Color orange = {226, 116, 17, 255};
    Color yellow = {237, 234, 4, 255};
    Color purple = {166, 0, 247, 255};
    Color cyan = {21, 204, 209, 255};
    Color blue = {13, 64, 216, 255};

    // Return a vector containing the defined colors
    return {darkGray, green, red, orange, yellow, purple, cyan, blue};
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
