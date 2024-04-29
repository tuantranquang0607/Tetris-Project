#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

// Declare a variable to store the last update time
double lastUpdateTime = 0;

bool EventTriggered(double interval) {
    // Get the current time
    double currentTime = GetTime();

    // Check if the time interval has passed
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() {
    // Initialize a window for the game with a width of 300 pixels, a height of 600 pixels, and the title "raylib Tetris tutorial"
    InitWindow(500, 620, "raylib Tetris Project");

    // Set the game to run at a target of 60 frames per second
    SetTargetFPS(60);

    // Create a Game object named game
    Game game = Game();

    // Set font
    Font font =LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    // The game loop. It will continue to run as long as the window should not close
    while (WindowShouldClose() == false) {
        // Update the music stream
        UpdateMusicStream(game.music);

        // Update the game
        game.HandleInput();

        // Signal the start of drawing commands
        BeginDrawing();

        // Clear the screen with the dark blue color
        ClearBackground(darkBlue);

        // Draw the game
        game.Draw();

        // Signal the end of drawing commands and displays everything that was drawn since the last call to BeginDrawing
        EndDrawing();

        // Move the block down every 0.2 seconds
        if (EventTriggered(0.2)) {
            game.MoveBlockDown();
        }

        // Draw the score and next block
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
    }

    // Close the window once the game loop has ended
    CloseWindow();
}
