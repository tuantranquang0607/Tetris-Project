#pragma once

#include "grid.h"
#include "blocks.cpp"

class Game {
    public:
        Game(); // Constructor for the Game class
        Block GetRandomBlock(); // Function to get a random block
        std::vector<Block> GetAllBlocks(); // Function to get all blocks
        void Draw(); // Function to draw the game
        void HandleInput(); // Function to handle user input
        void MoveBlockLeft(); // Function to move the current block to the left
        void MoveBlockRight(); // Function to move the current block to the right
        void MoveBlockDown(); // Function to move the current block down
        Grid grid; // Grid object to represent the game grid

    private:
        std::vector<Block> blocks; // Vector to store the blocks
        bool IsBlockOutside(); // Function to check if a block is outside the grid
        Block currentBlock; // Block object to represent the current block
        Block nextBlock; // Block object to represent the next block
};
