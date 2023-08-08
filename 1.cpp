#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

int arr[MAX_SIZE];
int size = 0;

void createArray() {
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    cout << "Array created successfully." << endl;
}

void displayArray() {
    cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement() {
    int index, value;
    cout << "Enter the index at which you want to insert: ";
    cin >> index;
    if (index < 0 || index > size) {
        cout << "Invalid index." << endl;
        return;
    }
    cout << "Enter the value to insert: ";
    cin >> value;

    for (int i = size; i > index; --i) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    size++;

    cout << "Value inserted successfully." << endl;
}

void deleteElement() {
    int index;
    cout << "Enter the index of the element to delete: ";
    cin >> index;
    if (index < 0 || index >= size) {
        cout << "Invalid index." << endl;
        return;
    }

    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    size--;

    cout << "Element deleted successfully." << endl;
}

void linearSearch() {
    int target;
    cout << "Enter the element to search for: ";
    cin >> target;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            cout << "Element found at index " << i << "." << endl;
            return;
        }
    }
    cout << "Element not found in the array." << endl;
}

int main() {
    int choice;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createArray();
                break;
            case 2:
                displayArray();
                break;
            case 3:
                insertElement();
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                linearSearch();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}

