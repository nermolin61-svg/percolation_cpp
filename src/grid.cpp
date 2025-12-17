#include "grid.h"
#include <random>
#include <cassert>

// прямоугольная сетка
std::vector<std::vector<int>> generateGrid(int rows, int cols, double p) {
    assert(rows > 0 && cols > 0);
    assert(p >= 0.0 && p <= 1.0);

    std::vector<std::vector<int>> grid(rows, std::vector<int>(cols));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(p);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            grid[i][j] = d(gen);

    return grid;
}

// квадратная сетка
std::vector<std::vector<int>> generateGrid(int N, double p) {
    return generateGrid(N, N, p);
}