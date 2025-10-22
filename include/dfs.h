#pragma once
#include <vector>

bool dfs(std::vector<std::vector<int>>& grid, int i, int j, std::vector<std::vector<bool>>& visited);
bool percolates(std::vector<std::vector<int>>& grid);
double estimateProbability(int N, double p, int trials);