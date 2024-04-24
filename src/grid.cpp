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
    for (int row = 0; row < numRows; row++) {
        // Loop through each column in the current row
        for (int column = 0; column < numCols; column++) {
            // Set the value at the current row and column of the grid to 0
            grid[row][column] = 0;
        }
    }
}

// Define the Print method to display the grid
void Grid::Print() {
    // Loop through each row
    for (int row = 0; row < numRows; row++) {
        // Loop through each column in the current row
        for (int column = 0; column < numCols; column++) {
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
    for (int row = 0; row < numRows; row++) {
        // Loop through each column in the current row
        for (int column = 0; column < numCols; column++) {
            // Get the value at the current row and column of the grid
            int cellValue = grid[row][column];

            // Draw a rectangle at the current cell's position with the color corresponding to the cell's value
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

// Function in the Grid class to check if a cell is outside the grid
bool Grid::IsCellOutside(int row, int column) {
    // If the row is between 0 and numRows (exclusive), and the column is between 0 and numCols (exclusive)
    if (row >= 0 && row < numRows && column >= 0 && column < numCols) {
        return false; // The cell is inside the grid, so return false
    }
    // If the cell is not inside the grid, return true
    return true;
}

// Function in the Grid class to check if a cell is empty
bool Grid::IsCellEmpty(int row, int column) {
    // Check if the value at the given row and column of the grid is 0
    if (grid[row][column] == 0) {
        return true;
    }
    return false;
}

int Grid::ClearFullRows() {
    int completed = 0;

    for (int row = numRows - 1; row >= 0; row--) {
        if (IsRowFull(row)) {
            ClearRow(row);
            completed++;
        } else if (completed > 0) {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

// Function in the Grid class to check if a row is full
bool Grid::IsRowFull(int row) {
    for (int column = 0; column < numCols; column++) {
        if (grid[row][column] == 0) {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row) {
    for (int column = 0; column < numCols; column++) {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows) {
    for (int column = 0; column < numCols; column++) {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
