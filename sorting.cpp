#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

/*
Had a theory that sorting an array of positive integers would be faster if split into multiple arrays based on the number of digits in each integer.
Wanted to test out the theory by implementing a simple bubble sort algorithm and comparing times between sorting the original array and then
sorting the split arrays.
*/

vector<int> bubbleSort(vector<int> arr) {
    int size = arr.size();
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
    return arr;
}

// Splits the input array into multiple arrays based on the number of digits in each integer
vector<vector<int>> splitArrayByDigits(vector<int> arr) {
    vector<vector<int>> splitArrays;
    for (int i = 0; i < arr.size(); i++) {
        //Should be fastest way to get the number of digits in an integer
        int numDigits = (arr[i] == 0) ? 1 : static_cast<int> (std::floor(std::log10(arr[i]))) + 1;
        while (splitArrays.size() < numDigits) {
            splitArrays.push_back(vector<int>());
        }
        splitArrays[numDigits - 1].push_back(arr[i]);
    }
    // Finnally sort the split arrays based on the number of digits in each integer
    for (int i = 0; i < splitArrays.size(); i++) {
        splitArrays[i] = bubbleSort(splitArrays[i]);
    }
    return splitArrays;
}

int main() {
    //List initialisation
    vector<int> unsortedVector = { 5, 2, 1, 4, 7, 6, 10, 3, 9, 8 };

    cout << "Unsorted array: ";
    for (int i = 0; i < unsortedVector.size(); i++) {
        cout << unsortedVector[i] << " ";
    }
    cout << endl;

    //Sort the array using bubble sort

    vector<int>sortedVector = bubbleSort(unsortedVector);

    cout << "Sorted array: ";
    for (int i = 0; i < sortedVector.size(); i++) {
        cout << sortedVector[i] << " ";
    }
    cout << endl;


    //Split the array into multiple arrays based on the number of digits in each integer
    vector<vector<int>> splitArrays = splitArrayByDigits(unsortedVector);

    cout << "Sorted array after splitting: ";
    for (int i = 0; i < splitArrays.size(); i++) {
        for (int j = 0; j < splitArrays[i].size(); j++) {
            cout << splitArrays[i][j] << " ";
        }
    }

    cout << endl;
    

    return 0;
}