#include <cmath>
#include <thread>
#include <random>
#include "cpu_loader.h"

#define M_PI_180 (M_PI / 180)

CpuLoader::CpuLoader():
size_(1000),
arrayInt_(size_),
arrayDouble_(size_) {
}

void CpuLoader::start() {
    const int numberOfThreads = 100;
    std::thread threads[numberOfThreads];
    for (auto &thread : threads) {
        thread = std::thread(&CpuLoader::calculate, this);
        thread.detach();
    }
}

void CpuLoader::calculate() {
    while (true) {
        calculateInteger();
        calculateDouble();
    }
}

void CpuLoader::calculateInteger() {
    for (int i = 0; i < size_ - 4; i++) {
        arrayInt_[i] = i + randInt(0, 100);
        arrayInt_[i + 1] = i - randInt(0, 100);
        arrayInt_[i + 2] = i * randInt(0, 100);
        arrayInt_[i + 3] = i / randInt(1, 100);
        arrayInt_[i + 4] = i % 3 * calculateFactorial(randInt(0, 300));
    }
    arrayInt_.sum();
}

void CpuLoader::calculateDouble() {
    for (int i = 0; i < size_ - 4; i++) {
        arrayDouble_[i] = i + cos(randDouble(0.0, 1.0)) * randDouble(0.0, 1.0);
        arrayDouble_[i + 1] = i - sin((randDouble(0.0, 99.0)) * M_PI_180) * randDouble(0.0, 1.0);
        arrayDouble_[i + 2] = i * tan((randDouble(0.0, 199.0)) * M_PI_180) * randDouble(0.0, 1.0);
        arrayDouble_[i + 3] = i / sin((randDouble(0.0, 299.0)) * M_PI_180) * randDouble(0.0, 1.0);
        arrayDouble_[i + 4] = i % 3 + cos(1) * calculateFactorial(randDouble(0.0, 300.0));
    }
    arrayDouble_.sum();
}

int CpuLoader::calculateFactorial(int x) {
    if (x == 0) {
        return 1;
    }
    return x * calculateFactorial(x - 1);
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
