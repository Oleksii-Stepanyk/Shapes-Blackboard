#pragma once
#include <vector>
#include "Shape.h"

class BlackBoard
{
    std::string availableShapes[3] = {
        "circle radius coordinates", "rectangle width height coordinates", "triangle height coordinates"
    };
    bool canUndo = false;
    int boardWidth = 0;
    int boardHeight = 0;
    std::vector<Shape*> shapes;
    std::vector<std::vector<char>> previousGrid;
    std::vector<std::vector<char>> grid;

    void drawCircle(int, int, int);
    void drawRectangle(int, int, int, int);
    void drawTriangle(int, int, int);

public:
    BlackBoard(int, int);

    void draw();
    void list() const;
    void showShapes();
    void addShape(std::vector<std::string>& parameters);
    void undo();
    void clear();

    std::vector<std::string> _getShapes();
    std::string getHeight() const;
    std::string getWidth() const;
};
