#pragma once
#include <string>
#include <utility>

class Shape
{
protected:
    int id = 0;
    std::string type;

public:
    Shape(const int*, std::string)
    {
    }

    virtual ~Shape() = default;
};

class Circle final : public Shape
{
    int radius;
    int x;
    int y;

public:
    Circle(const int* id, const int*, const int*, const int*) : Shape(id, "circle")
    {
    }

    int getRadius() const;
    int getX() const;
    int getY() const;
};

class Rectangle final : public Shape
{
    int width;
    int height;
    int x;
    int y;

public:
    Rectangle(const int* id, const int*, const int*, const int*, const int*) : Shape(id, "rectangle")
    {
    }

    int getWidth() const;
    int getHeight() const;
    int getX() const;
    int getY() const;
};

class Triangle final : public Shape
{
    int height;
    int x;
    int y;

public:
    Triangle(const int* id, const int*, const int*, const int*) : Shape(id, "triangle")
    {
    }

    int getHeight() const;
    int getX() const;
    int getY() const;
};
