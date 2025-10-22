#include "C:\Users\nermo\OneDrive\Рабочий стол\AMPh\1_semester\C++_in_photonics_tasks\Percolation\include\grid.h"
#include <random>

std::vector<std::vector<int>> generateGrid(int N, double p) {
    std::vector<std::vector<int>> grid(N, std::vector<int>(N));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(p);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            grid[i][j] = d(gen);

    return grid;
}