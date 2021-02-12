/** 
 * @file CpuLoader.h
 * @brief CpuLoader class reference
 * @author anzipex (anzipex@gmail.com)
 * @date July 26, 2017
 */

#pragma once

#include <valarray>

/**
 * @brief CPU and coprocessor loader
 */
class CpuLoader {
public:
    CpuLoader();

    /**
     * @brief Load the CPU and coprocessor
     */
    void start();

private:

    /**
     * @brief Perpetual cycle with calculations for CPU and coprocessor
     */
    void calculate();

    /**
     * @brief Calculations for CPUs
     */
    void calculateInteger();

    /**
     * @brief Calculations for the coprocessor
     */
    void calculateFloat();

    /**
     * @brief Counts the factorial
     * @param x, accepted value
     * @return calculate the factorial
     */
    int calcualteFactorial(int x);

    /**
     * @brief Counts random integers in the specified range
     * @param min, from what value
     * @param max, until which value
     * @return Calculated result
     */
    int randInt(int min, int max);

    /**
     * @brief Counts random floating point numbers in the specified range
     * @param min, from what value
     * @param max, until which value
     * @return Calculated result
     */
    double randDouble(double min, double max);

    const int _size; //!< size for containers valarray
    std::valarray<int> _arrayInt; //!< container for integer values
    std::valarray<double> _arrayDouble; //!< container for floating-point numbers
};
