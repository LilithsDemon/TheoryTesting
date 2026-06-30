#include <iostream>
using namespace std;

/*
Had a theory that sorting an array of positive integers would be faster if split into multiple arrays based on the number of digits in each integer.
Wanted to test out the theory by implementing a simple bubble sort algorithm and comparing times between sorting the original array and then
sorting the split arrays.
*/

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int unsorted[10] = { 5, 2, 1, 4, 7, 6, 10, 3, 9, 8 };
    int size = sizeof(unsorted) / sizeof(unsorted[0]);


    
    cout << "Unsorted array: ";
    for (int i = 0; i < size; i++) {
        cout << unsorted[i] << " ";
    }
    cout << endl;

    bubbleSort(unsorted, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << unsorted[i] << " ";
    }
    cout << endl;

    return 0;
}