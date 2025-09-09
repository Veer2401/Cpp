#include <iostream>
using namespace std;

class Stack{

    private:
        int arr[100],top,maxSize=100;

    public:
        Stack(int size){
            if(size > 100) {
                cout << "Size is large!";
                exit(0);
                
            } else {
                maxSize = size;
            }
            top = -1;
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }

        bool isFull(){
            if(top == maxSize - 1){
                return true;
            } else{
                return false;
            }
        }

        void push(int value){
            if(isFull()){
                cout << "The stack is full! Cannot add elements";
            }else{
                arr[++top] = value;
                cout << value << " pushed to stack" << endl;
            }
        }

        void pop(int value){
            if(isEmpty()){
                cout << "Stack is empty! Cannot remove elements";
            } else{
                arr[top--] = value;
                cout << value << " removed from the stack" << endl;
            }

        }

        void display(){
            if(isEmpty()){
                cout << "Stack is empty!";
            }else{
                cout << "Stack contents: ";
                for(int i=0;i<=top;i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    int size;
    cout << "Enter stack size (max 100) ";
    cin >> size;

    Stack s(size);
    int choice,value;

    do
    {
        cout << "\nChoose an option:\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice){
            case 1: 
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

            case 2:
            s.pop(value);
            break;

            case 3:
            s.display();
            break;

            case 4:
            cout << "Exit";

            default:
            cout << "Invalid choice!";
        }
    } while (true);
    
}