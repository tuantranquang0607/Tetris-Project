// Include the raylib library
#include <raylib.h>
#include "grid.h"

// The main function where the program starts
int main()
{
    // Create a Color variable named darkblue
    Color darkblue = {44, 44, 127, 255};

    // Initialize a window for the game with a width of 300 pixels, a height of 600 pixels, and the title "raylib Tetris tutorial"
    InitWindow(300, 600, "raylib Tetris tutorial");

    // Set the game to run at a target of 60 frames per second
    SetTargetFPS(60);

    // Create an instance of the Grid class
    Grid grid = Grid();

    // Set the value at the first row and first column of the grid to 1
    grid.grid[0][0] = 1;

    // Set the value at the fourth row and sixth column of the grid to 4
    grid.grid[3][5] = 4;

    // Set the value at the eighteenth row and ninth column of the grid to 7
    grid.grid[17][8] = 7;

    // Print the grid to the console
    grid.Print();

    // The game loop. It will continue to run as long as the window should not close
    while(WindowShouldClose() == false)
    {
        // Signal the start of drawing commands
        BeginDrawing();

        // Clear the screen with the darkblue color
        ClearBackground(darkblue);

        // Call the Draw method of the grid object
        grid.Draw();

        // Signal the end of drawing commands and displays everything that was drawn since the last call to BeginDrawing
        EndDrawing();
    }

    // Close the window once the game loop has ended
    CloseWindow();
}
