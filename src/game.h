#pragma once

#include "grid.h"
#include "blocks.cpp"

class Game {
    public:
        Game(); // Constructor for the Game class
        void Draw(); // Function to draw the game
        void HandleInput(); // Function to handle user input
        void MoveBlockDown(); // Function to move the current block down
        bool gameOver; // Function to check if the game is over
        int score; // Function to store the score

    private:
        Grid grid; // Grid object to represent the game grid
        void MoveBlockLeft(); // Function to move the current block to the left
        void MoveBlockRight(); // Function to move the current block to the right
        Block GetRandomBlock(); // Function to get a random block
        std::vector<Block> GetAllBlocks(); // Function to get all blocks
        std::vector<Block> blocks; // Vector to store the blocks
        bool IsBlockOutside(); // Function to check if a block is outside the grid
        Block currentBlock; // Block object to represent the current block
        Block nextBlock; // Block object to represent the next block
        void RotateBlock(); // Function to rotate the current block
        void LockBlock(); // Function to lock the current block in place
        bool BlockFits(); // Function to check if the block fits in the grid
        void Reset(); // Function to reset the game
        void UpdateScore(int linesCleared, int moveDownPoints); // Function to update the score
};
