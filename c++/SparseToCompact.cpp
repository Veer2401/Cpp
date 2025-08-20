#include <iostream>
using namespace std;

int sparseToCompact(int A[][10], int rows, int cols, int compact[][3]) {
    int count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (A[i][j] != 0)
                count++;

    compact[0][0] = rows;
    compact[0][1] = cols;
    compact[0][2] = count;

    int k = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (A[i][j] != 0) {
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = A[i][j];
                k++;
            }
    return count;
}

void printMatrix(int A[][10], int rows,int cols){
    cout << "Original matrix\n";
    for(int i=0;i<rows;i++){
        for(int j=0;i<cols;j++){
            cout << A[i][j] << " ";
            cout << "\n";
        }
    }
}

void printCompact(int compact[][3]) {
    int count = compact[0][2];
    for (int i = 0; i <= count; i++)
        cout << compact[i][0] << " " << compact[i][1] << " " << compact[i][2] << "\n";
}

void transposeCompact(int compact[][3], int transpose[][3]) {
    int count = compact[0][2];

    transpose[0][0] = compact[0][1];
    transpose[0][1] = compact[0][0];
    transpose[0][2] = count;

    int k = 1;

    for (int col = 0; col < compact[0][1]; col++) {
        for (int i = 1; i <= count; i++) {
            if (compact[i][1] == col) {
                transpose[k][0] = compact[i][1];
                transpose[k][1] = compact[i][0];
                transpose[k][2] = compact[i][2];
                k++;
            }
        }
    }
}


int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int sparse[10][10];
    cout << "Enter the matrix elements row-wise:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> sparse[i][j];

    printMatrix(sparse,rows,cols);

    int compact[rows * cols + 1][3];
    sparseToCompact(sparse, rows, cols, compact);

    cout << "\nCompact matrix representation (row col value):\n";
    printCompact(compact);

    int transpose[rows * cols + 1][3];
    transposeCompact(compact, transpose);

    cout << "\nTranspose of compact matrix (row col value):\n";
    printCompact(transpose);

    return 0;
}