#include "block.h"
#include "position.h"

// A class that represents an L-shaped block
class LBlock : public Block {
    public:
        LBlock(){
            // Set the block ID to 1
            id = 1; 
            // Define the shape of the block in its four rotation states
            cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
            cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
        };
};

// A class that represents an J-shaped block
class JBlock : public Block {
    public:
        JBlock(){
            // Set the block ID to 2
            id = 2;
            // Define the shape of the block in its four rotation states
            cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
            cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
        };
};

// A class that represents an I-shaped block
class IBlock : public Block {
    public:
        IBlock(){
            // Set the block ID to 3
            id = 3;
            // Define the shape of the block in its four rotation states
            cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
            cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
            cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
            cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
        };
};

// A class that represents an O-shaped block
class OBlock : public Block {
    public:
        OBlock(){
            // Set the block ID to 4
            id = 4;
            // Define the shape of the block in its four rotation states
            cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
            cells[1] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
            cells[2] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
            cells[3] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        };
};

// A class that represents an S-shaped block
class SBlock : public Block {
    public:
        SBlock(){
            // Set the block ID to 5
            id = 5;
            // Define the shape of the block in its four rotation states
            cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
            cells[1] = {Position(0, 1), Position(1, 0), Position(1, 2), Position(2, 2)};
            cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
            cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
        };
};

// A class that represents an T-shaped block
class TBlock : public Block {
    public:
        TBlock(){
            // Set the block ID to 6
            id = 6;
            // Define the shape of the block in its four rotation states
            cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
            cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        };
};

// A class that represents an B-shaped block
class ZBlock : public Block {
    public:
        ZBlock(){
            // Set the block ID to 7
            id = 7;
            // Define the shape of the block in its four rotation states
            cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
            cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
        };
};