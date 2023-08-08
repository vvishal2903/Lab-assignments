#include <iostream>

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

    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size <= 0 || size > MAX_SIZE) {
        std::cout << "Invalid array size." << std::endl;
        return 1;
    }

    std::cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    // Sort the array to group duplicates together
    sortArray(arr, size);

    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        // Skip duplicates
        while (i + 1 < size && arr[i] == arr[i + 1]) {
            ++i;
        }

        // Copy unique element to the new array
        arr[newSize] = arr[i];
        ++newSize;
    }

    // Display the array with unique elements
    std::cout << "Array with unique elements: ";
    for (int i = 0; i < newSize; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
