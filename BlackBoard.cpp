#include "BlackBoard.h"
#include <iostream>

BlackBoard::BlackBoard(const int Height, const int Width) : grid(Height, std::vector(Width, ' '))
{
}

void BlackBoard::draw()
{
    for (auto& i : grid)
    {
        for (char j : i)
        {
            std::cout << j;
        }
    }
}

void BlackBoard::list() const
{
    for (auto shape : shapes)
    {
        if (auto* currentShape = dynamic_cast<Circle*>(shape))
        {
            std::cout << currentShape->getId() << " circle " << currentShape->getRadius() << ' ' << currentShape->getX()
                << ' ' << currentShape->getY() << '\n';
        }
        else if (auto* currentShape = dynamic_cast<Rectangle*>(shape))
        {
            std::cout << currentShape->getId() << " rectangle " << currentShape->getWidth() << ' ' << currentShape->
                getHeight()
                << ' ' << currentShape->getX() << ' ' << currentShape->getY() << '\n';
        }
        else if (auto* currentShape = dynamic_cast<Triangle*>(shape))
        {
            std::cout << currentShape->getId() << " triangle " << currentShape->getHeight() << ' ' << currentShape->
                getX()
                << ' ' << currentShape->getY() << '\n';
        }
    }
}

void BlackBoard::showShapes()
{
    for (std::string& shape : availableShapes)
    {
        std::cout << shape << '\n';
    }
}

void BlackBoard::addShape(std::vector<std::string>& parameters)
{
    if (parameters.size() < 4 || parameters.size() > 5)
    {
        std::cout << "Invalid parameters\n";
    }
    else if (parameters[0] == "circle" && parameters.size() == 4)
    {
        int radius = std::stoi(parameters[1]);
        int x = std::stoi(parameters[2]);
        int y = std::stoi(parameters[3]);
        auto* circle = new Circle(shapes.size() + 1, radius, x, y);
        shapes.push_back(circle);
        //drawCircle(radius, x, y);
        previousGrid = grid;
        canUndo = true;
    }
    else if (parameters[0] == "rectangle" && parameters.size() == 5)
    {
        int width = std::stoi(parameters[1]);
        int height = std::stoi(parameters[2]);
        int x = std::stoi(parameters[3]);
        int y = std::stoi(parameters[4]);
        auto* rectangle = new Rectangle(shapes.size() + 1, width, height, x, y);
        shapes.push_back(rectangle);
        //drawRectangle(width, height, x, y);
        previousGrid = grid;
        canUndo = true;
    }
    else if (parameters[0] == "triangle" && parameters.size() == 4)
    {
        int height = std::stoi(parameters[1]);
        int x = std::stoi(parameters[2]);
        int y = std::stoi(parameters[3]);
        auto* triangle = new Triangle(shapes.size() + 1, height, x, y);
        shapes.push_back(triangle);
        //drawTriangle(height, x, y);
        previousGrid = grid;
        canUndo = true;
    }
    else
    {
        std::cout << "Invalid command\n";
    }
}

void BlackBoard::undo()
{
    if (canUndo)
    {
        grid = previousGrid;
        previousGrid.clear();

        const auto lastShape = shapes.back();
        shapes.pop_back();
        delete lastShape;

        canUndo = false;
    }
    else
    {
        std::cout << "Nothing to undo\n";
    }
}

void BlackBoard::clear()
{
    grid = std::vector(grid.size(), std::vector(grid[0].size(), ' '));
    previousGrid.clear();
    canUndo = false;
    for (const auto shape : shapes)
    {
        delete shape;
    }
    shapes.clear();
}

std::vector<std::string> BlackBoard::_getShapes()
{
    std::vector<std::string> shapeCommands;
    std::string command;
    for (auto shape : shapes)
    {
        if (auto* currentShape = dynamic_cast<Circle*>(shape))
        {
            command += "add circle " + std::to_string(currentShape->getRadius()) + ' '
                + std::to_string(currentShape->getX()) + ' ' + std::to_string(currentShape->getY()) + '\n';
        }
        else if (auto* currentShape = dynamic_cast<Rectangle*>(shape))
        {
            command += "add rectangle " + std::to_string(currentShape->getWidth()) + ' '
                + std::to_string(currentShape->getHeight()) + ' ' + std::to_string(currentShape->getX()) + ' '
                + std::to_string(currentShape->getY()) + '\n';
        }
        else if (auto* currentShape = dynamic_cast<Triangle*>(shape))
        {
            command += "add triangle " + std::to_string(currentShape->getHeight()) + ' '
                + std::to_string(currentShape->getX()) + ' ' + std::to_string(currentShape->getY()) + '\n';
        }
        shapeCommands.push_back(command);
        command.clear();
    }
    return shapeCommands;
}