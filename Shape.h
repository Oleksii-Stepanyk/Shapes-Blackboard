#pragma once
#include <string>

class Shape
{
protected:
    int id = 0;
    std::string type;
    int x;
    int y;

public:
    Shape(int, std::string, int, int);
    virtual ~Shape() = default;
    int getId() const;
    std::string getType() const;
    int getX() const;
    int getY() const;
};

class Circle final : public Shape
{
    int radius;

public:
    Circle(int, int, int, int);
    int getRadius() const;
};

class Rectangle final : public Shape
{
    int width;
    int height;

public:
    Rectangle(int, int, int, int, int);
    int getWidth() const;
    int getHeight() const;
};

class Triangle final : public Shape
{
    int height;

public:
    Triangle(int, int, int, int);
    int getHeight() const;
};
