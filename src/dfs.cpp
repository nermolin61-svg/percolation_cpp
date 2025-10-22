#include "C:\Users\nermo\OneDrive\Рабочий стол\AMPh\1_semester\C++_in_photonics_tasks\Percolation\include\dfs.h"
#include "C:\Users\nermo\OneDrive\Рабочий стол\AMPh\1_semester\C++_in_photonics_tasks\Percolation\include\grid.h"

bool dfs(std::vector<std::vector<int>>& grid, int i, int j, std::vector<std::vector<bool>>& visited) {
    int N = grid.size();
    if (i < 0 || j < 0 || i >= N || j >= N) return false;
    if (!grid[i][j] || visited[i][j]) return false;
    if (i == N - 1) return true; // достигли нижней границы

    visited[i][j] = true;

    return dfs(grid, i + 1, j, visited) ||
           dfs(grid, i - 1, j, visited) ||
           dfs(grid, i, j + 1, visited) ||
           dfs(grid, i, j - 1, visited);
}

bool percolates(std::vector<std::vector<int>>& grid) {
    int N = grid.size();
    std::vector<std::vector<bool>> visited(N, std::vector<bool>(N, false));

    for (int j = 0; j < N; ++j) {
        if (grid[0][j] == 1 && dfs(grid, 0, j, visited))
            return true;
    }
    return false;
}

double estimateProbability(int N, double p, int trials) {
    int success = 0;
    for (int t = 0; t < trials; ++t) {
        auto grid = generateGrid(N, p);
        if (percolates(grid)) success++;
    }
    return static_cast<double>(success) / trials;
}
