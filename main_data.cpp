
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "insertion_sort.cpp"
#include "selection_sort.cpp"
#include "bubble_sort.cpp"

using namespace std;

void readData(const string& filename, vector<int>& data) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }

    int number;
    while (file >> number) {
        data.push_back(number);
    }

    file.close();
}

void runAndMeasureSort(void (*sortFunction)(vector<int>&, int&), const string& algorithmName, const string& filename, ofstream& resultFile) {
    vector<int> data;
    readData(filename, data);

    int numOperations = 0;
    auto start = chrono::high_resolution_clock::now();
    sortFunction(data, numOperations);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = end - start;

    resultFile << algorithmName << " on " << filename << ":\n";
    resultFile << "Running time: " << elapsed.count() << " seconds\n";
    resultFile << "Number of operations: " << numOperations << "\n\n";
}

int main() {
    // Open a file to write results, clearing the file if it exists
    ofstream resultFile("results.txt", ios::trunc);
    if (!resultFile) {
        cerr << "Error opening results file for writing." << endl;
        return 1; // Return a non-zero value to indicate error
    }

    // Add a header to indicate a new execution
    resultFile << "=========================\n";
    resultFile << "Execution Time: " << chrono::system_clock::to_time_t(chrono::system_clock::now()) << "\n";
    resultFile << "=========================\n\n";

    vector<string> files = {"data_1000.txt", "data_5000.txt", "data_10000.txt"};
    
    for (const auto& file : files) {
        runAndMeasureSort(insertionSort, "Insertion Sort", file, resultFile);
        runAndMeasureSort(selectionSort, "Selection Sort", file, resultFile);
        runAndMeasureSort(bubbleSort, "Bubble Sort", file, resultFile);
    }

    // Close the results file
    resultFile.close();

    return 0;
}

