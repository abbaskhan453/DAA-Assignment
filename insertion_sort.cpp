// insertion_sort.cpp
#include <vector>

void insertionSort(std::vector<int>& arr, int& numOperations) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
            ++numOperations;
        }
        arr[j + 1] = key;
        ++numOperations;
    }
}
