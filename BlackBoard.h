#pragma once
#include <vector>
#include "Shape.h"

class BlackBoard
{
    std::string availableShapes[3] = {
        "circle radius coordinates", "rectangle width height coordinates", "triangle height coordinates"
    };
    bool canUndo = false;
    std::vector<Shape*> shapes;
    std::vector<std::vector<char>> previousGrid;
    std::vector<std::vector<char>> grid;

public:
    BlackBoard(int, int);

    void draw();
    void list() const;
    void showShapes();
    void addShape(std::vector<std::string>& parameters);
    void undo();
    void clear();
    std::vector<std::string> _getShapes();
};
