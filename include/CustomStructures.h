#ifndef CUSTOM_STRUCT_H
#define CUSTOM_STRUCT_H
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#endif // CUSTOM_STRUCT_H


// Plane vector variable
struct PVector
{
    int X;
    int Y;

    PVector(int x = 0, int y = 0)
    {
        X = x;
        Y = y;
    };

    std::string ToString()
    {
        return "X: " + std::to_string(X) + " Y: " + std::to_string(Y);
    }

    void operator + (PVector Object)
    {
        X += Object.X;
        Y += Object.Y;
    }

    void operator - (PVector Object)
    {
        X -= Object.X;
        Y -= Object.Y;
    }

    void operator += (PVector Object)
    {
        X += Object.X;
        Y += Object.Y;
    }

    void operator -= (PVector Object)
    {
        X -= Object.X;
        Y -= Object.Y;
    }

    void operator = (PVector Object)
    {
        X = Object.X;
        Y = Object.Y;
    }
};
