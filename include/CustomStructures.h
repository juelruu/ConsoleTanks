#ifndef CUSTOM_STRUCT_H
#define CUSTOM_STRUCT_H
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <string.h>
#define Srite std::vector<std::string>
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
};
