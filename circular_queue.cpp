#include <iostream>

// Define the maximum size of the circular queue
const int MAX_SIZE = 100;

class CircularQueue {
private:
    int front, rear, size;
    int arr[MAX_SIZE];

public:
    CircularQueue() {
        front = rear = -1;
        size = 0;
    }

    // Function to check if the circular queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the circular queue is full
    bool isFull() {
        return size == MAX_SIZE;
    }

    // Function to add an element to the circular queue (enqueue)
    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = item;
        size++;
    }

    // Function to remove an element from the circular queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }

        size--;
    }

    // Function to display the elements in the circular queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        std::cout << "Queue Elements: ";
        int i = front;
        do {
            std::cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);

        std::cout << std::endl;
    }
};

int main() {
    CircularQueue queue;
    int choice, item;

    while (true) {
        std::cout << "Circular Queue Menu:" << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Display" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the element to enqueue: ";
                std::cin >> item;
                queue.enqueue(item);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}
