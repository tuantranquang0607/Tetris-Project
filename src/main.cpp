#include <raylib.h>
#include "game.h"

int main()
{
    // Create a Color variable named darkblue
    Color darkblue = {44, 44, 127, 255};

    // Initialize a window for the game with a width of 300 pixels, a height of 600 pixels, and the title "raylib Tetris tutorial"
    InitWindow(300, 600, "raylib Tetris tutorial");

    // Set the game to run at a target of 60 frames per second
    SetTargetFPS(60);

    // Create a Game object named game
    Game game = Game();

    // The game loop. It will continue to run as long as the window should not close
    while (WindowShouldClose() == false)
    {
        // Update the game
        game.HandleInput();

        // Signal the start of drawing commands
        BeginDrawing();

        // Clear the screen with the darkblue color
        ClearBackground(darkblue);

        // Draw the game
        game.Draw();

        // Signal the end of drawing commands and displays everything that was drawn since the last call to BeginDrawing
        EndDrawing();
    }

    // Close the window once the game loop has ended
    CloseWindow();
}
