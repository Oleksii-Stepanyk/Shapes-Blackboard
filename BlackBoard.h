#pragma once
#include <vector>
#include "Shape.h"

class BlackBoard
{
    std::string availableShapes[3] = {
        "circle radius coordinates", "rectangle width height coordinates", "triangle height coordinates"
    };
    std::vector<Shape> shapes;
    std::vector<std::vector<char>> previousGrid;
    std::vector<std::vector<char>> grid;

public:
    BlackBoard(const int* Height, const int* Width) : grid(*Height, std::vector(*Width, ' '))
    {
    }

    void draw();
    void list();
    void showShapes();
    void addShape(std::vector<std::string>& parameters);
    void undo();
    void clear();
};
