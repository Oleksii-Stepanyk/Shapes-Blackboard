#pragma once
#include <cstdio>
#include <string>

class FileHandler
{
    FILE* file;

public:
    explicit FileHandler(const std::string*);
    ~FileHandler();
    std::string getData();
    void writeData(const std::string&);
    bool isOpen() const { return file != nullptr; }
};
