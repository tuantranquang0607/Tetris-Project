#pragma once

#include <vector>
#include <raylib.h>

// Define a class named Grid.
class Grid {
    public:
        // Declare a constructor for the Grid class.
        Grid();

        // Declare a method to initialize the grid.
        void Initialize();

        // Declare a method to print the grid.
        void Print();

        // Declare a 2D array named grid with 20 rows and 10 columns.
        int grid[20][10];

        // Declare a method to draw the grid.
        void Draw();

    private:
        // Declare an integer to store the number of rows in the grid.
        int numRows;

        // Declare an integer to store the number of columns in the grid.
        int numCols;

        // Declare an integer to store the size of a cell.
        int cellSize;

        // Declare a vector to store the colors of the cells.
        std::vector<Color> colors;
};
