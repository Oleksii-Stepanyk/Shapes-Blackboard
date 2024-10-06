#include <iostream>
#include <sstream>
#include "UIKernel.h"
#include "FileHandler.h"

std::vector<std::string> split(const std::string& str, const char& delimiter)
{
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;
    while (getline(ss, item, delimiter))
    {
        result.push_back(item);
    }
    return result;
}


UIKernel::UIKernel()
{
    std::cout << "Enter the height and width of the board: ";
    int height, width;
    std::cin >> height >> width;
    board = std::make_unique<BlackBoard>(height, width);
}

void UIKernel::startProgram()
{
    std::string input;
    std::cin.ignore();
    while (input != "exit")
    {
        std::cout << "Enter command: ";
        getline(std::cin, input);
        parseCommand(input);
    }
}

void UIKernel::parseCommand(const std::string& input)
{
    std::vector<std::string> args = split(input, ' ');
    if (args.empty())
    {
        std::cout << "Invalid command. Please try again.\n";
    }
    else if (args[0] == "draw")
    {
        board->draw();
    }
    else if (args[0] == "list")
    {
        board->list();
    }
    else if (args[0] == "shapes")
    {
        board->showShapes();
    }
    else if (args[0] == "add")
    {
        args.erase(args.begin());
        board->addShape(args);
    }
    else if (args[0] == "undo")
    {
        board->undo();
    }
    else if (args[0] == "clear")
    {
        board->clear();
    }
    else if (args[0] == "save")
    {
        saveFile();
    }
    else if (args[0] == "load")
    {
        loadFile();
    }
    else if (args[0] == "exit")
    {
        std::cout << "Exiting program...\n";
    }
    else
    {
        std::cout << "Invalid command. Please try again.\n";
    }
}

void UIKernel::loadFile()
{
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    const FileHandler file(filename, "r");
    if (!file.isOpen())
    {
        std::cout << "Error: File not found.\n";
        return;
    }

    const std::string data = file.getData();
    if (data.empty())
    {
        std::cout << "Error: File is empty.\n";
        return;
    }

    std::vector<std::string> lines = split(data, '\n');
    if (lines[0] != "board version 1.0")
    {
        std::cout << "Error: Invalid file format.\n";
        return;
    }

    lines.erase(lines.begin());
    for (const std::string& line : lines)
    {
        parseCommand(line);
    }
}

void UIKernel::saveFile()
{
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    const FileHandler file(filename, "w");
    if (!file.isOpen())
    {
        std::cout << "Error: File not found.\n";
        return;
    }

    file.writeData("board version 1.0\n");
    for (const std::string& shapeCommand : board->_getShapes())
    {
        file.writeData(shapeCommand + '\n');
    }
}
