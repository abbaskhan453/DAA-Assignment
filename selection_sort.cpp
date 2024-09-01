
// selection_sort.cpp
#include <vector>

void selectionSort(std::vector<int>& arr, int& numOperations) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            ++numOperations;
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

