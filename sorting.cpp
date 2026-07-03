#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include <vector>
#include <cstdlib>
using namespace std;

/*
Had a theory that sorting an array of positive integers would be faster if split into multiple arrays based on the number of digits in each integer.
Wanted to test out the theory by implementing a simple bubble sort algorithm and comparing times between sorting the original array and then
sorting the split arrays.
*/

class Sorter {
    private:
        vector<int> unsortedVector;

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

    public:
        Sorter(int size) {
            std::random_device rd; // obtain a random number from hardware
            std::mt19937 gen(rd()); // seed the generator
            std::uniform_int_distribution<> distr(0, 10000); // define the range
            for (int i = 0; i < size; i++) {
                unsortedVector.push_back(distr(gen));
            }
        }

        void getUnsortedVector() {
            cout << "Unsorted array: ";
            for (int i = 0; i < unsortedVector.size(); i++) {
                cout << unsortedVector[i] << " ";
            }
            cout << endl;
        }

        void getSortedVector() {
            vector<int> sortedVector = bubbleSort(unsortedVector);
            for (int i = 0; i < sortedVector.size(); i++) {
                cout << sortedVector[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    vector<Sorter> sets = {Sorter(1000), Sorter(10000), Sorter(100000), Sorter(1000000), Sorter(10000000), Sorter(100000000)};
    

    return 0;
}