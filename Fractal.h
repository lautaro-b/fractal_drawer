//
// Created by lautaro on 9/4/19.
//

#include <string>


#ifndef CPP_EX2_FRACTAL_H
#define CPP_EX2_FRACTAL_H


#define PIXEL '#'
#define SPACE ' '


/**
 * This class represents the portrayal of a general fractal
 */
class Fractal
{
public:

    /**
     *  draws the fractal
     */
    virtual void draw() = 0; //Pure virtual

    /**
     *  draws a pixel
     */
    void drawPixel() {std::cout <<  PIXEL; }

    /**
     *  draws a space
     */
    void drawSpace() {std::cout <<  SPACE; }

    /**
     *
     * @return the dimension of the fractal
     */
    int getDimension() {return _dimension; }

    /**
     * virtual destructor.
     */
    virtual ~Fractal() = default;

protected:
    int _dimension; /**the dimension of the fractal*/

    /**
     *
     * @param dimension
     */
    Fractal(int dimension) : _dimension(dimension) {}


    /**
     * copy constructor
     * @param other
     */
    Fractal(const Fractal& other) = default;

    /**
     * move constructor
     * @param other
     */
    Fractal(Fractal && other) = default;

    /**
     * (copy) operator =
     * @param other
     * @return
     */
    Fractal& operator=(const Fractal& other) = default;

    /**
     * move operator =
     * @param other
     * @return
     */
    Fractal& operator=(Fractal && other) = default;



    /**
    *
    * @param row - the location on the row
    * @param column - the location on the column
    */
    virtual void drawHelper(int row, int column) = 0;


};

/**
 * This class represents the portrayal of a fractal of type Sierpinski Carpet
 */
class Carpet : public Fractal
{
public:

    /**
     *
     * @param dimension
     */
    Carpet(int dimension): Fractal(dimension) {}

    /**
     *  (default) destructor
     */
    ~Carpet() {}

    /**
     *  draws the Carpet fractal
     */
    void draw() override;

    /**
     * copy constructor
     * @param other
     */
    Carpet(const Carpet& other) = default;

    /**
     * move constructor
     * @param other
     */
    Carpet(Carpet && other) = default;

    /**
     * (copy) operator =
     * @param other
     * @return
     */
    Carpet& operator=(const Carpet& other) = default;

    /**
     * move operator =
     * @param other
     * @return
     */
    Carpet& operator=(Carpet && other) = default;

private:

    /**
     *
     * @param row
     * @param column
     */
    virtual void drawHelper(int row, int column) override;

};


/**
 * This class represents the portrayal of a fractal of type Sierpinski Sieve
 */
class Sieve : public Fractal
{
public:

    /**
     *
     * @param dimension
     */
    Sieve(int dimension) : Fractal(dimension) {}

    /**
     *
     */
    ~Sieve() {}

    /**
     *
     */
    void draw() override;

    /**
     * copy constructor
     * @param other
     */
    Sieve(const Sieve& other) = default;

    /**
     * move constructor
     * @param other
     */
    Sieve(Sieve && other) = default;

    /**
     * (copy) operator =
     * @param other
     * @return
     */
    Sieve& operator=(const Sieve& other) = default;

    /**
     * move operator =
     * @param other
     * @return
     */
    Sieve& operator=(Sieve && other) = default;



private:

    /**
    *
    * @param row
    * @param column
    */
    virtual void drawHelper(int row, int column) override;

};


/**
 * This class represents the portrayal of a fractal of type Cantor Dust
 */
class CantorDust : public Fractal
{
public:
    /**
     *
     * @param dimension
     */
    CantorDust(int dimension) : Fractal(dimension) {}

    /**
     * default ctor
     */
    ~CantorDust() {}

    /**
     *  draws the Cantor Dust fractal
     */
    void draw() override;

    /**
     * copy constructor
     * @param other
     */
    CantorDust(const CantorDust& other) = default;

    /**
     * move constructor
     * @param other
     */
    CantorDust(CantorDust && other) = default;

    /**
     * (copy) operator =
     * @param other
     * @return
     */
    CantorDust& operator=(const CantorDust& other) = default;

    /**
     * move operator =
     * @param other
     * @return
     */
    CantorDust& operator=(CantorDust && other) = default;


private:
    /**
    * a helper function for draw()
    * @param row
    * @param column
    */
    virtual void drawHelper(int row, int column) override;

};



#endif //CPP_EX2_FRACTAL_H
