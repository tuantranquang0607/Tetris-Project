#pragma once

#include <vector>
#include <raylib.h>

// Define a class named Grid.
class Grid {
    public:
        Grid(); // Declare a constructor for the Grid class.
        void Initialize(); // Declare a method to initialize the grid.
        void Print(); // Declare a method to print the grid.
        void Draw(); // Declare a method to draw the grid.
        bool IsCellOutside(int row, int column); // Function to check if a cell is outside the grid
        bool IsCellEmpty(int row, int column); // Function to check if a cell is empty
        int grid[20][10]; // Declare a 2D array named grid with 20 rows and 10 columns.
        int ClearFullRows(); // Function to clear full rows

    private:
        int numRows; // Declare an integer to store the number of rows in the grid.
        int numCols; // Declare an integer to store the number of columns in the grid.
        int cellSize; // Declare an integer to store the size of a cell.
        bool IsRowFull(int row); // Function to check if a row is full
        void ClearRow(int row); // Function to clear a row
        void MoveRowDown(int row, int numRows); // Function to move a row down

        std::vector<Color> colors; // Declare a vector to store the colors of the cells.
};
