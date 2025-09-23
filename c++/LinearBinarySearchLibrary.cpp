#include <iostream>
using namespace std;

struct Book{
    int id;
    string title,author;
};

void linearSearch(Book books[],int n,string author){
    bool found = false;
    cout << "\nSearching for books.." << endl;
    for(int i=0;i<n;i++){
        if(books[i].author == author){
            cout << "Book found! " << endl;
            cout << "ID: " << books[i].id << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            found = true;
        }
    }
    if(!found){
        cout << "No book was found! " << endl;
    }
}

int binarySearch(Book books[],int n,int id){
    int low=0,mid,high = n-1;

    while(low <= high){
        int mid = (low+high)/2;
        if(books[mid].id == id){
            return mid;
        }
        else if(books[mid].id < id){
            low = mid + 1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter number of Books: ";
    cin >> n;

    Book books[n];
    cout << "Enter the book details: " << endl;
    for(int i=0;i<n;i++){
        cout << "ID: ";
        cin >> books[i].id;
        cout << "Title: ";
        cin >> books[i].title;
        cout << "Author: ";
        cin >> books[i].author;
    }

    int choice;

    do{
        cout << "\n--- Library Management System ---";
        cout << "\n1. Linear Search by Author";
        cout << "\n2. Binary Search by Book ID";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        if(choice == 1){
            string author;
            cout << "Enter author name: ";
            cin >> author;
            linearSearch(books,n,author);
        }
        else if(choice == 2){
            int id;
            cout << "Enter Book id to search: ";
            cin >> id;

            int index = binarySearch(books,n,id);
            if(index != -1){
                cout << "Book found!" << endl;
                cout << "ID: " << books[index].id << endl;
                cout << "Title: " << books[index].title << endl;
                cout << "Author: " << books[index].author << endl;
            }
            else{
                cout << "Book Not found! " << endl;
            }
        }
    }while(choice != 3);

    return 0;
}