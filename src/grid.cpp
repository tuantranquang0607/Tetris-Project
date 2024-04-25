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

            // Draw a rectangle for the cell at the appropriate position and color
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
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

// Function in the Grid class to clear full rows
int Grid::ClearFullRows() {
    // Initialize a variable to store the number of completed rows
    int completed = 0;

    // Loop through each row from the bottom to the top
    for (int row = numRows - 1; row >= 0; row--) {
        // Check if the current row is full
        if (IsRowFull(row)) {
            ClearRow(row); // Clear the row if it is full
            completed++; // Increment the number of completed rows
        } else if (completed > 0) {
            MoveRowDown(row, completed); // Move the row down by the number of completed rows
        }
    }
    return completed;
}

// Function in the Grid class to check if a row is full
bool Grid::IsRowFull(int row) {
    // Loop through each column in the given row
    for (int column = 0; column < numCols; column++) {
        // If any cell in the row is empty, return false
        if (grid[row][column] == 0) {
            return false;
        }
    }
    return true;
}

// Function in the Grid class to clear a row
void Grid::ClearRow(int row) {
    // Loop through each column in the given row
    for (int column = 0; column < numCols; column++) {
        grid[row][column] = 0; // Set the value in the current row to 0
    }
}

// Function in the Grid class to move a row down
void Grid::MoveRowDown(int row, int numRows) {
    // Loop through each column in the given row
    for (int column = 0; column < numCols; column++) {
        grid[row + numRows][column] = grid[row][column]; // Move the value from the current row to the row below
        grid[row][column] = 0; // Set the value in the current row to 0
    }
}
