#include "game.h"
#include <random>

// Constructor for the Game class
Game::Game() {
    grid = Grid(); // Initialize the grid
    blocks = GetAllBlocks(); // Get all types of blocks
    currentBlock = GetRandomBlock(); // Get a random block as the current block
    nextBlock = GetRandomBlock(); // Get a random block as the next block
    gameOver = false; // Set the game over flag to false
}

// Function to get a random block
Block Game::GetRandomBlock() {
    if (blocks.empty()) {
        blocks = GetAllBlocks(); // If the blocks vector is empty, get all types of blocks
    }

    int randomIndex = rand() % blocks.size(); // Generate a random index
    Block block = blocks[randomIndex]; // Get the block at the random index

    blocks.erase(blocks.begin() + randomIndex); // Remove the block from the blocks vector

    return block; // Return the random block
};

// Function to get all types of blocks
std::vector<Block> Game::GetAllBlocks() {
    return {LBlock(), JBlock(), IBlock(), OBlock(), TBlock(), SBlock(), ZBlock()}; // Return a vector of all types of blocks
}

// Function to draw the game
void Game::Draw() {
    grid.Draw(); // Draw the grid
    currentBlock.Draw(); // Draw the current block
}

// Function to handle user input
void Game::HandleInput() {
    int keyPressed = GetKeyPressed(); // Get the key pressed by the user

    // Restart the game if it is over and a key is pressed
    if (gameOver && keyPressed != 0) {
        gameOver = false; 
        Reset();
    }

    // Perform an action based on the key pressed
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft(); // If the left key is pressed, move the block to the left
        break;
    case KEY_RIGHT:
        MoveBlockRight(); // If the right key is pressed, move the block to the right
        break;
    case KEY_DOWN:
        MoveBlockDown(); // If the down key is pressed, move the block down
        break;
    case KEY_UP:
        RotateBlock(); // If the up key is pressed, rotate the block
        break;
    }
}

// Function to move the block to the left
void Game::MoveBlockLeft() {
    if (!gameOver) {
        currentBlock.Move(0, -1); // Move the block to the left

        if (IsBlockOutside() || BlockFits() == false) {
            currentBlock.Move(0, 1); // If the block is outside the grid, move it back to the right
        }
    }
}

// Function to move the block to the right
void Game::MoveBlockRight() {
    if (!gameOver) {
        currentBlock.Move(0, 1); // Move the block to the right

        if (IsBlockOutside() || BlockFits() == false) {
            currentBlock.Move(0, -1); // If the block is outside the grid, move it back to the left
        }
    }
}

// Function to move the block down
void Game::MoveBlockDown() {
    if (!gameOver) {
        currentBlock.Move(1, 0); // Move the block down

        if (IsBlockOutside() || BlockFits() == false) {
            currentBlock.Move(-1, 0); // If the block is outside the grid, move it back up
            LockBlock(); // Lock the block in place
        }
    }
}

// Function to check if a block is outside the grid
bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition(); // Get the positions of the cells in the current block
    
    for (Position item : tiles) {
        if (grid.IsCellOutside(item.row, item.column)) {
            return true; // If a cell is outside the grid, return true
        }
    }
    return false; // If no cells are outside the grid, return false
}

// Function to rotate the block
void Game::RotateBlock() {
    if (!gameOver) {
        currentBlock.Rotate(); // Rotate the block

        if (IsBlockOutside() || BlockFits() == false) {
            currentBlock.UndoRotation(); // If the block is outside the grid, undo the rotation
        }
    }
}

// Function to lock the block in place
void Game::LockBlock() {
    std::vector<Position> tiles = currentBlock.GetCellPosition(); // Get the positions of the cells in the current block

    for (Position item : tiles) {
        grid.grid[item.row][item.column] = currentBlock.id; // Set the value of the cell in the grid to the block's id
    }

    currentBlock = nextBlock; // Set the current block to the next block
    nextBlock = GetRandomBlock(); // Get a new random block as the next block
    grid.ClearFullRows(); // Clear any full rows in the grid

    if (BlockFits() == false) {
        gameOver = true; // If the new block does not fit in the grid, set the game over flag to true
    }
}

// Function to check if the block fits in the grid
bool Game::BlockFits() {
    std::vector<Position> tiles = currentBlock.GetCellPosition(); // Get the positions of the cells in the current block

    for (Position item : tiles) {
        if (grid.IsCellEmpty(item.row, item.column) == false){
            return false; // If a cell is occupied, return false
        }
    }
    return true; // If no cells are occupied, return true
}

void Game::Reset() {
    grid.Initialize(); // Initialize the grid
    blocks = GetAllBlocks(); // Get all types of blocks
    currentBlock = GetRandomBlock(); // Get a random block as the current block
    nextBlock = GetRandomBlock(); // Get a random block as the next block
}

