#pragma once

#include <raylib.h>
#include <vector>

/* The extern keyword is used to declare a variable or function that is defined in another file or in another scope. 
    This allows the variable or function to be used across different files or scopes.*/
// Declare external constant Color variables
extern const Color darkGray;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightBlue;
extern const Color darkBlue;

// Declare an external function GetCellColors that returns a vector of Color
std::vector<Color> GetCellColors();
