#include <iostream>
#include "UIKernel.h"
#include "TextFormat.h"

UIKernel::UIKernel()
{
    std::cout << "Enter the height and width of the board: ";
    int height, width;
    std::cin >> height >> width;
    board = new BlackBoard(&height, &width);
}

UIKernel::~UIKernel()
{
    delete board;
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
    std::vector<std::string> args = TextFormat::split(input, ' ');
    switch (args[0])
    {
    case "draw":
        board->draw();
        break;
    default:
        std::cout << "Invalid command. Please try again.\n";
        break;
    }
    // TODO: Implement the rest of the commands inside switch case
    
    // if (args[0] == "draw")
    // {
    //     board->draw();
    // }
    // else if (args[0] == "list")
    // {
    //     board->list();
    // }
    // else if (args[0] == "shapes")
    // {
    //     board->showShapes();
    // }
    // else if (args[0] == "add")
    // {
    //     args.erase(args.begin());
    //     board->addShape(args);
    // }
    // else
    // {
    //     std::cout << "Invalid command. Please try again.\n";
    // }
}
