#pragma once
#include <string>
#include "BlackBoard.h"

class UIKernel
{
    BlackBoard* board;

public:
    UIKernel();
    ~UIKernel();
    void startProgram();
    void parseCommand(const std::string&);
    void loadFile(const std::string&);
    void saveFile(const std::string&);
};
