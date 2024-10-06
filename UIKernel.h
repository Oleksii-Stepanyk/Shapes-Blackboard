#pragma once
#include <memory>
#include <string>
#include "BlackBoard.h"

class UIKernel
{
    std::unique_ptr<BlackBoard> board;

public:
    UIKernel();
    ~UIKernel() = default;
    void startProgram();
    void parseCommand(const std::string&);
    void loadFile();
    void saveFile();
};