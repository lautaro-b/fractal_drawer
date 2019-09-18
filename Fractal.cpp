//
// Created by lautaro on 9/4/19.
//

#include <iostream>
#include <assert.h>
#include <math.h>
#include "Fractal.h"

#define TRIDIMENSIONAL 3
#define TWODIMENSIONAL 2


/**
 * draws a fractal of type Carpet
 */
void Carpet::draw()
{
    int size = static_cast<int>(pow(TRIDIMENSIONAL, _dimension));

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            drawHelper(i, j);
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

/**
 *
 * @param row - the location on the row
 * @param column - the location on the column
 */
void Carpet::drawHelper(int row, int column)
{
        if (row == 0 || column == 0)
        {
            drawPixel();
            return;
        }

        else if (row % 3 == 1 && column % 3 == 1)
        {
            drawSpace();
            return;
        }

        row /= 3;
        column /= 3;
        drawHelper(row, column);

}


/**
 * draws a fractal of type Sieve
 */
void Sieve::draw()
{
    int size = static_cast<int>(pow(TWODIMENSIONAL, _dimension));

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            drawHelper(i, j);
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

/**
 *
 * @param row - the location on the row
 * @param column - the location on the column
 */
void Sieve::drawHelper(int row, int column)
{

    if (row == 0 || column == 0)
    {
        drawPixel();
        return;
    }

    else if (row % 2 == 1 && column % 2 == 1)
    {
        drawSpace();
        return;
    }

    row /= 2;
    column /= 2;
    drawHelper(row, column);

}


/**
 * draws a fractal of type Cantor Dust
 */
void CantorDust::draw()
{
    int size = static_cast<int>(pow(TRIDIMENSIONAL, _dimension));

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            drawHelper(i, j);
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


/**
 *
 * @param row - the location on the row
 * @param column - the location on the column
 */
void CantorDust::drawHelper(int row, int column)
{

    if (row % 3 == 1 || column % 3 == 1)
    {
        drawSpace();
        return;
    }

    else if (row == 0  && column == 0)
    {
        drawPixel();
        return;
    }

    row /= 3;
    column /= 3;
    drawHelper(row, column);
}


