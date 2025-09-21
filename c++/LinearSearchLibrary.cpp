#include <iostream>
using namespace std;

class Library{
    public:
    string ISBN,bookName,authName,pubName;


     void inputBook() {
        cout << "Enter ISBN: ";
        cin >> ISBN;
        cout << "Enter Book Name: ";
        cin >> bookName;
        cout << "Enter Author Name: ";
        cin >> authName;
        cout << "Enter Publisher Name: ";
        cin >> pubName;
    }

     void displayBook() {
        cout << "ISBN: " << ISBN << "\nBook Name: " << bookName
             << "\nAuthor: " << authName << "\nPublisher: " << pubName << "\n";
    }

};

void searchBook(Library books[],int n,int choice,string key){
    bool found = false;
    int i=0;

    while(i<n){
    if((choice == 1 && books[i].ISBN == key ||
        choice == 2 && books[i].bookName == key || 
        choice == 3 && books[i].authName == key ||
        choice == 4 && books[i].pubName == key)){

            cout << "\nBook Found." << endl;
            books[i].displayBook();
            found = true;
        }
        i++;
    }

    if(!found){
        cout << "No book found!";
    }
}

int main(){
    int n;

    cout << "Enter number of books: ";
    cin >> n;

    Library books[100];
    for(int i=0;i<n;i++){
        cout << "Enter details for Book " << i+1 << endl;
        books[i].inputBook();
    }

    int choice;
    string key;
    char again = 'y';

    while(again == 'y' || again == 'Y'){
        cout << "\nSearch Book By:\n1. ISBN\n2. Book Name\n3. Author Name\n4. Publisher Name\nEnter choice: ";
        cin >> choice;
        cout << "Enter search key: ";
        cin >> key;

        searchBook(books,n,choice,key);

        cout << "Do you want to search again? (Y/N)";
        cin >> again;

        if(again == 'N' || again == 'n'){
            cout << "Exiting Program.";
            exit(0);
        }
    }
    return 0;
}