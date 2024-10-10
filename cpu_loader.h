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
    void calculateDouble();

    /**
     * @brief Counts the factorial
     * @param x, accepted value
     * @return calculate the factorial
     */
    int calculateFactorial(int x);

    /**
     * @brief Counts random integers in the specified range
     * @param min, from what value
     * @param max, until which value
     * @return Calculated result
     */
    int randInt(int min, int max);

    /**
     * @brief Counts random doubles in the specified range
     * @param min, from what value
     * @param max, until which value
     * @return Calculated result
     */
    double randDouble(double min, double max);

    const int size_; //!< size for containers val-array
    std::valarray<int> arrayInt_; //!< container for integer values
    std::valarray<double> arrayDouble_; //!< container for double values
};
