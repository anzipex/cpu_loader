# CPU and Coprocessor Loader

This program is designed to generate a heavy computational load on both the CPU and the floating-point coprocessor (FPU) by performing continuous calculations in parallel using multiple threads. The program carries out intensive integer and floating-point operations, making it suitable for stress-testing or benchmarking processors.

## Features

- **Multi-threaded Execution**: The program spawns 100 threads, each running continuously and independently to maximize CPU usage.
- **Integer Calculations**: Performs complex operations on an array of integers, including addition, subtraction, multiplication, division, and modular arithmetic combined with factorial calculations.
- **Floating-point (Double) Calculations**: Utilizes mathematical functions such as cosine, sine, and tangent on an array of doubles, applying these functions to randomly generated numbers.
- **Random Number Generation**: Each operation uses random integers and floating-point numbers to vary the computational workload.
- **Recursive Factorial Calculation**: A recursive function calculates the factorial of random numbers, adding more complexity and workload to the processor.

## How It Works

1. **Thread Management**: The program initializes 100 threads, each continuously executing integer and floating-point calculations in an infinite loop.
2. **Integer Calculations**: For each element in the integer array, a sequence of arithmetic operations is performed, some of which include random numbers and factorials.
3. **Floating-point Calculations**: For each element in the double array, trigonometric functions (cosine, sine, tangent) are applied to random floating-point values.
4. **Random Values**: Random integers and floating-point numbers are generated on the fly, ensuring that each calculation is unique and contributes to the computational load.

## Usage

Simply run the program to start the computation. It will continue indefinitely, loading both the CPU and FPU.
