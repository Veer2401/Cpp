#include <iostream>
using namespace std;

int sparseToCompact(int A[][10],int rows,int cols,int compact[][3]){
    int count = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(A[i][j] != 0){
                count++;
            }
        }
    }

    compact[0][0] = rows;
    compact[0][1] = cols;
    compact[0][2] = count;

    int k=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(A[i][j] != 0){
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = A[i][j];
                k++;
            }
            
        }
    }
    return count;
}

void print(int compact[][3]){
    int count = compact[0][2];
    cout << "Row Columns Value\n";
    for(int i=0;i<=count;i++){
        cout << compact[i][0] << " " << compact[i][1] << " " << compact[i][2] << endl;
    }
}

int main(){
    int rows,cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int sparse[10][10];
    cout << "Enter matrix elements: " << endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin >> sparse[i][j];
        }
    }

    int compact[rows * cols+1][3];

    sparseToCompact(sparse,rows,cols,compact);

    cout << "The compact matrix is: " << endl;
    print(compact);

    return 0;
}
