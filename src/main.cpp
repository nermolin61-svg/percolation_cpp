#include <iostream>
#include "C:\Users\nermo\OneDrive\Рабочий стол\AMPh\1_semester\C++_in_photonics_tasks\Percolation\include\grid.h"
#include "C:\Users\nermo\OneDrive\Рабочий стол\AMPh\1_semester\C++_in_photonics_tasks\Percolation\include\dfs.h"

int main() {
    int N = 20;          // размер сетки
    double p = 0.55;     // вероятность, что ячейка проводит
    int trials = 100;    // количество испытаний

    double prob = estimateProbability(N, p, trials);
    std::cout << "Mesh size: " << N << "x" << N << std::endl;
    std::cout << "Probability of conductivity (p): " << p << std::endl;
    std::cout << "Probability of failure assessment: " << prob << std::endl;

    return 0;
}
