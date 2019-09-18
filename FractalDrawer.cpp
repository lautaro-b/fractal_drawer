#include <iostream>
#include "Fractal.h"
#include <fstream>
#include <vector>

#define INVALID "Invalid input"
#define USAGE "Usage: FractalDrawer <file path>"
#define LINE_SIZE 3
#define MIN_TYPE 1
#define MAX_TYPE 3
#define MIN_DIM 1
#define MAX_DIM 6
#define TO_INT - '0'
#define CARPET 1
#define SIEVE 2
#define CANTOR_DUST 3
#define SEPARATOR ','
#define ARG_NUM 2

/**
 * main function
 * @return 0 if the program succeeds
 */
int main(int argc, char* argv[])

{
    if (argc != ARG_NUM)
    {
        std::cerr << USAGE << std::endl;
        exit(EXIT_FAILURE);
    }

//    auto *cantorDust = new CantorDust(3);
//    cantorDust->draw();


    std::string line;
    int fractalType;
    int dimension;

    std::vector<Fractal*> fractals;

    std::ifstream file;

    file.open(argv[1]);

    if (!file.is_open())
    {
        std::cerr << INVALID << std::endl;
        return EXIT_FAILURE;
    }

    if (file.fail())
    {
        file.close();
        std::cerr << INVALID << std::endl;
        return EXIT_FAILURE;
    }

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        file.close();
        return 0;
    }


    while (!file.eof())
    {
        getline(file, line);

        if (line.empty() && file.eof())
        {
            break;
        }


        if (file.fail())
        {
            file.close();
            std::cerr << INVALID << std::endl;
            return EXIT_FAILURE;
        }


        if (line.size() != LINE_SIZE)
        {
            file.close();
            std::cerr << INVALID << std::endl;
            return EXIT_FAILURE;
        }

        if (line[0] TO_INT > MAX_TYPE || (line[0] TO_INT < MIN_TYPE) || (line[2] TO_INT > MAX_DIM) ||
            (line[2] TO_INT < MIN_DIM) || (line[1] != SEPARATOR))
        {
            file.close();
            std::cerr << INVALID << std::endl;
            return EXIT_FAILURE;
        }

        fractalType = line[0] TO_INT;
        dimension = line[2] TO_INT;

        switch (fractalType)
        {
            case CARPET:
                fractals.push_back(new Carpet(dimension));
                break;
            case SIEVE:
                fractals.push_back(new Sieve(dimension));
                break;
            case CANTOR_DUST:
                fractals.push_back(new CantorDust(dimension));
                break;

            default:
                break;
        }
    }

    while (!fractals.empty())
    {
        Fractal * fractal = fractals.back();
        fractal->draw();

        delete(fractal);
        fractals.pop_back();
    }

    file.close();
    return 0;
}