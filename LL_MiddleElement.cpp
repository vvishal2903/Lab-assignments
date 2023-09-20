#include <iostream>

// Define a structure for a node in the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to find the middle element of a linked list
Node* findMiddle(Node* head) {
    if (head == nullptr) {
        return nullptr; // Empty list
    }

    Node* slow_ptr = head;
    Node* fast_ptr = head;

    while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
        slow_ptr = slow_ptr->next;         // Move slow_ptr by one step
        fast_ptr = fast_ptr->next->next;   // Move fast_ptr by two steps
    }

    return slow_ptr; // The slow_ptr is now at the middle element
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Linked List: ";
    printList(head);

    Node* middle = findMiddle(head);

    if (middle != nullptr) {
        std::cout << "Middle element: " << middle->data << std::endl;
    } else {
        std::cout << "The list is empty." << std::endl;
    }

    // Free the memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
