
// generate_data.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void generateRandomNumbers(const std::string& filename, int size) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    std::srand(std::time(nullptr)); // Seed the random number generator

    for (int i = 0; i < size; ++i) {
        file << std::rand() % 10000 << "\n"; // Random number between 0 and 9999
    }

    file.close();
}

int main() {
    generateRandomNumbers("data_1000.txt", 1000);
    generateRandomNumbers("data_5000.txt", 5000);
    generateRandomNumbers("data_10000.txt", 10000);
    return 0;
}

