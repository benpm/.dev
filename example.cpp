#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

// Simple example demonstrating modern C++ features
// Compile: clang++ -std=c++23 -o example example.cpp
// Run: ./example

int main() {
    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Using C++23 ranges to filter and transform
    auto even_squared = numbers
        | std::views::filter([](int n) { return n % 2 == 0; })
        | std::views::transform([](int n) { return n * n; });

    std::cout << "Even numbers squared: ";
    for (auto n : even_squared) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
