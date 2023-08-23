#include<iostream>

using namespace std;

class Stack {
private:
    int capacity;
    int top;
    int items[100];

public:
    Stack(int size) {
        capacity = size;
        top = -1;
    }
    void push(int item)
    {
        if (top < capacity - 1) {
            ++top;
            items[top] = item;
            cout << "Pushed: " << item << endl;
        } 
        else {
            cout << "Stack is full. Cannot push." << endl;
        }
    }
    void pop()
    {
        if(!isEmpty())
        {
                cout<<"popped:"<<items[top--]<<endl;
        }
        else{
            cout<<"Stack empty"<<endl;
        }
    }
    bool isEmpty()
    {
        return top==-1;
    }
    bool isFull()
    {
        return top==capacity-1;
    }
    void display()
    {
        if(!isEmpty())
        {
            for(int i=0;i<top;i++)
            {
                cout<<"Element at index "<<i<<"="<<items[i]<<endl;
            }
        }
        else{
            cout<<"Stack empty"<<endl;
        }
    }
    void peek()
    {
        if (!isEmpty())
        {
            cout<<items[top]<<endl;
        }
        else
        cout<<"Stack empty"<<endl;
    }    
};
int main()
{
    int capacity;
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;

    Stack stack(capacity);

    while (true) {
        cout << "\n----------Menu-----------" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                int item;
                cout << "Enter item to push: ";
                cin >> item;
                stack.push(item);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                if (stack.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 4:
                if (stack.isFull()) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;
            case 5:
                stack.display();
                break;
            case 6:
                stack.peek();
                break;
            case 7:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
    return 0;
}
