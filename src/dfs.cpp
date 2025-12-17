#include "dfs.h"
#include "grid.h"
#include <queue>
#include <utility>
#include <cassert>
#include <cmath>

// DFS
bool dfs(std::vector<std::vector<int>>& grid, int i, int j,
    std::vector<std::vector<bool>>& visited) {
    int rows = (int)grid.size();
    int cols = (int)grid[0].size();

    if (i < 0 || j < 0 || i >= rows || j >= cols) return false;
    if (!grid[i][j] || visited[i][j]) return false;
    if (i == rows - 1) return true;

    visited[i][j] = true;

    return dfs(grid, i + 1, j, visited) ||
        dfs(grid, i - 1, j, visited) ||
        dfs(grid, i, j + 1, visited) ||
        dfs(grid, i, j - 1, visited);
}

// BFS 
bool percolatesBFS(std::vector<std::vector<int>>& grid) {
    int rows = (int)grid.size();
    int cols = (int)grid[0].size();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::queue<std::pair<int, int>> q;

    for (int j = 0; j < cols; ++j) {
        if (grid[0][j]) {
            q.push(std::make_pair(0, j));
            visited[0][j] = true;
        }
    }

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if (i == rows - 1) return true;

        
        int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        for (int d = 0; d < 4; ++d) {
            int dx = directions[d][0];
            int dy = directions[d][1];
            int ni = i + dx;
            int nj = j + dy;

            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols &&
                grid[ni][nj] && !visited[ni][nj]) {
                visited[ni][nj] = true;
                q.push(std::make_pair(ni, nj));
            }
        }
    }

    return false;
}


bool percolates(std::vector<std::vector<int>>& grid) {
    // BFS
    return percolatesBFS(grid);
}

// Оценка пробоя прямоугольной сетки
double estimateProbability(int rows, int cols, double p, int trials) {
    assert(trials > 0);

    int success = 0;
    for (int t = 0; t < trials; ++t) {
        auto grid = generateGrid(rows, cols, p);
        if (percolates(grid)) success++;
    }
    return static_cast<double>(success) / trials;
}

double estimateProbability(int N, double p, int trials) {
    return estimateProbability(N, N, p, trials);
}