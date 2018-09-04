#include <cassert>
#include <iostream>
#include <otus/matrix.hpp>

void run() {
    constexpr size_t SIZE = 10;
    otus::Matrix<int, 0> matrix;

    // 1. Add first matrix diagonal from 0 to 9
    for (size_t i = 1; i < SIZE; ++i) {
        matrix[i][i] = i;
    }

    // 2. Add second matrix diagonal from 9 to 0
    for (size_t i = 1; i < SIZE; ++i) {
        matrix[i][SIZE - i - 1] = i;
    }

    // 3. Show count set values in matrix
    for (size_t i = 1; i < SIZE - 1; ++i) {
        for (size_t j = 1; j < SIZE - 1; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    // 4. Show matrix size
    std::cout << "\nMatrix size: " << matrix.size() << std::endl;

    // 5. Show all set value in matrix
    std::cout << "Elements:\n";
    for (const auto &element : matrix) {
        int x, y, value;
        std::tie(x, y, value) = element;
        std::cout << "  * [" << x << "][" << y << "] = " << value << '\n';
    }
}

int main(int, char *[]) {
    try {
        run();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}