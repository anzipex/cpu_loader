/** 
 * @file CpuLoader.cpp
 * @brief Implementing the CpuLoader
 * @author anzipex (anzipex@gmail.com)
 * @date July 26, 2017
 */

#include <math.h>
#include <iostream>
#include <thread>
#include <random>
#include "CpuLoader.h"

#define M_PI_180 M_PI / 180

CpuLoader::CpuLoader():
_size(1000),
_arrayInt(_size),
_arrayDouble(_size) {
}

void CpuLoader::start() {
    int numberOfThreads = 100;
    std::thread threads[numberOfThreads];
    for (auto &thread : threads) {
        thread = std::thread(&CpuLoader::calculate, this);
        thread.detach();
    }
}

void CpuLoader::calculate() {
    while (true) {
        calculateInteger();
        calculateFloat();
    }
}

void CpuLoader::calculateInteger() {
    for (int i = 0; i < _size - 4; i++) {
        _arrayInt[i] = i + randInt(0, 100);
        _arrayInt[i + 1] = i - randInt(0, 100);
        _arrayInt[i + 2] = i * randInt(0, 100);
        _arrayInt[i + 3] = i / randInt(1, 100);
        _arrayInt[i + 4] = i % 3 * calcualteFactorial(randInt(0, 300));
    }
    _arrayInt.sum();
}

void CpuLoader::calculateFloat() {
    for (int i = 0; i < _size - 4; i++) {
        _arrayDouble[i] = i + cos(randDouble(0.0, 1.0)) * randDouble(0.0, 1.0);
        _arrayDouble[i + 1] = i - sin((randDouble(0.0, 99.0)) * M_PI_180) * randDouble(0.0, 1.0);
        _arrayDouble[i + 2] = i * tan((randDouble(0.0, 199.0)) * M_PI_180) * randDouble(0.0, 1.0);
        _arrayDouble[i + 3] = i / sin((randDouble(0.0, 299.0)) * M_PI_180) * randDouble(0.0, 1.0);
        _arrayDouble[i + 4] = i % 3 + cos(1) * calcualteFactorial(randDouble(0.0, 300.0));
    }
    _arrayDouble.sum();
}

int CpuLoader::calcualteFactorial(int x) {
    if (x == 0) {
        return 1;
    }
    return x * calcualteFactorial(x - 1);
}

int CpuLoader::randInt(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    std::random_device rd;
    std::default_random_engine generator(rd());
    return distribution(generator);
}

double CpuLoader::randDouble(double min, double max) {
    std::uniform_real_distribution<double> distribution(min, max);
    std::random_device rd;
    std::default_random_engine generator(rd());
    return distribution(generator);
}
