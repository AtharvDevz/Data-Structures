#include <iostream>
#include <vector>

using namespace std;

int partition(int arr, int low, int high) {
    int pivot = (low + high) / 2;
    while (true) {
        while (arr[low] < pivot) {
            low++;
        }
        while (arr[high] > pivot) {
            high--;
        }
        if (low >= high) {
            return high;
        }
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void quicksort(int arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int myArray[7] = {3, 6, 8, 10, 1, 2, 1};

    quicksort(myArray, 0, 7);

    cout << "Sorted array: ";
    for (int i = 0; i < 7; i++) {
        cout << myArray[i] << " ";
    }

    return 0;
}
