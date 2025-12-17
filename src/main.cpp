#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include "grid.h"
#include "dfs.h"

// серия экспериментов
void runExperiments(const std::string& filename,
    int rows, int cols,
    double p_start, double p_end, double p_step,
    int trials) {

    std::ofstream data_file(filename);
    if (!data_file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // заголовок файла с данными эксперимента
    data_file << "# Percolation data\n";
    data_file << "# Grid size: " << rows << "x" << cols << "\n";
    data_file << "# Trials per p: " << trials << "\n";
    data_file << "# p\tP(percolation)\tstd_error\n";

    std::cout << "\nRunning percolation experiments..." << std::endl;
    std::cout << "Grid size: " << rows << "x" << cols << std::endl;
    std::cout << "Trials per p: " << trials << std::endl;
    std::cout << "p from " << p_start << " to " << p_end
        << " with step " << p_step << std::endl;

    // эксперименты для разных p
    int steps = static_cast<int>((p_end - p_start) / p_step) + 1;
    for (int step = 0; step <= steps; ++step) {
        double p = p_start + step * p_step;
        if (p > p_end + 1e-9) break;

        double prob = estimateProbability(rows, cols, p, trials);

        // стандартная ошибка
        double std_error = std::sqrt(prob * (1 - prob) / trials);

        data_file << std::fixed << std::setprecision(4)
            << p << "\t" << prob << "\t" << std_error << "\n";

        if (step % 2 == 0) {
            std::cout << "p = " << std::setw(4) << p
                << " -> P(percolation) = " << std::setw(6) << prob
                << " ± " << std::setw(6) << 1.96 * std_error << std::endl;
        }
    }

    data_file.close();
    std::cout << "\nData saved to '" << filename << "'" << std::endl;
}

void studyAspectRatio() {
    std::cout << "\n=== Studying aspect ratio effects ===" << std::endl;

    double p = 0.55;
    int trials = 500;

    std::ofstream aspect_file("aspect_ratio_data.txt");
    if (!aspect_file.is_open()) {
        std::cerr << "Error aspect ratio file!" << std::endl;
        return;
    }

    aspect_file << "# Aspect ratio \n";
    aspect_file << "# p = " << p << ", trials = " << trials << "\n";
    aspect_file << "# width\theight\tP(percolation)\n";

    
    for (int width = 10; width <= 50; width += 10) {
        for (int height = 10; height <= 100; height += 20) {
            double prob = estimateProbability(height, width, p, trials);
            aspect_file << width << "\t" << height << "\t" << prob << "\n";

            std::cout << "Size " << width << "x" << height
                << " -> P = " << prob << std::endl;
        }
    }

    aspect_file.close();
    std::cout << "Aspect ratio data saved to 'aspect_ratio_data.txt'" << std::endl;
}

int main() {
    std::cout << "=== Percolation Simulation ===" << std::endl;
    std::cout << "Data files in: " << std::endl;

    // квадратная сетка
    std::cout << "\n=== Square Grid ===" << std::endl;
    runExperiments("square_grid.txt", 10, 10, 0.1, 0.9, 0.05, 100); 

    // прямоугольная сетка_1
    std::cout << "\n=== Wide Grid ===" << std::endl;
    runExperiments("wide_grid.txt", 5, 20, 0.1, 0.9, 0.05, 100); 

    // прямоугольная сетка_2
    std::cout << "\n=== Tall Grid ===" << std::endl;
    runExperiments("tall_grid.txt", 20, 5, 0.1, 0.9, 0.05, 100); 

    // соотношения сторон
    studyAspectRatio();

    
    std::cout << "Files created:" << std::endl;
    std::cout << "  - square_grid.txt" << std::endl;
    std::cout << "  - wide_grid.txt" << std::endl;
    std::cout << "  - tall_grid.txt" << std::endl;
    std::cout << "  - aspect_ratio_data.txt" << std::endl;
    

    return 0;
}