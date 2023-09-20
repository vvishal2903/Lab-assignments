#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


Node* findMiddle(Node* head) {
    if (head == nullptr) {
        return nullptr; 
    }

    Node* slow_ptr = head;
    Node* fast_ptr = head;

    while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
        slow_ptr = slow_ptr->next;         
        fast_ptr = fast_ptr->next->next;   
    }

    return slow_ptr; 
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
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

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
