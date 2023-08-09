#include <iostream>

using namespace std;
const int MAX_SIZE = 100;

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main() {
    int arr[MAX_SIZE];
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0 || size > MAX_SIZE) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    sortArray(arr, size);
    cout<<"Displaying the sorted array:"<< endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
