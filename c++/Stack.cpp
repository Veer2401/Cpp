#include <iostream>
using namespace std;

class Stack {

private:
    int arr[100], top, maxSize = 100;

public:
    Stack(int size) {
        if (size > 100) {
            cout << "Size is large!";
            exit(0);
        }
        else {
            maxSize = size;
        }
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "The stack is full! Cannot add elements" << endl;
        }
        else {
            arr[++top] = value;
            cout << value << " pushed to stack" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot remove elements" << endl;
        }
        else {
            cout << arr[top--] << " removed from the stack" << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        }
        else {
            cout << "Stack contents: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter stack size (max 100): ";
    cin >> size;

    Stack s(size);
    int choice, value;

    do {
        cout << "\nChoose an option:\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.display();
            break;

        case 4:
            cout << "Exit" << endl;
            return 0;  // Exit the program

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (true);
}
