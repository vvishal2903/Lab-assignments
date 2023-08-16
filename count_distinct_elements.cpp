#include <iostream>
using namespace std;

int count(int arr[], int n) {
    int c = 0;

    for (int i = 0; i < n; ++i) {
    int j;    
        for (j = 0; j < i; ++j) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        if (j == i) {
            c++;
        }
    }

    return c;
}

int main() {
    int arr[] = {4, 2, 8, 6, 3, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int distinctCount = count(arr, n);

    cout << "Total number of distinct elements: " << distinctCount << endl;

    return 0;
}
