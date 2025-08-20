#include <iostream>
using namespace std;

int main() {
    int r1, c1;
    int matrix1[100][100];

    cout << "ENTER THE NUMBER OF ROWS: (Matrix 1)" << endl;
    cin >> r1;
    cout << "ENTER THE NUMBER OF COLUMNS: (Matrix 1)" << endl;
    cin >> c1;

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << "Element [" << i << "] [" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }

    int count1 = 0;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (matrix1[i][j] != 0) {
                count1++;
            }
        }
    }

    int compact1[count1 + 1][3];
    compact1[0][0] = r1;
    compact1[0][1] = c1;
    compact1[0][2] = count1;

    int k1 = 1;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (matrix1[i][j] != 0) {
                compact1[k1][0] = i;
                compact1[k1][1] = j;
                compact1[k1][2] = matrix1[i][j];
                k1++;
            }
        }
    }

    
    int r2, c2;
    int matrix2[100][100];

    cout << "ENTER THE NUMBER OF ROWS: (Matrix 2)" << endl;
    cin >> r2;
    cout << "ENTER THE NUMBER OF COLUMNS: (Matrix 2)" << endl;
    cin >> c2;

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cout << "Element [" << i << "] [" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }

    int count2 = 0;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            if (matrix2[i][j] != 0) {
                count2++;
            }
        }
    }

    int compact2[count2 + 1][3];
    compact2[0][0] = r2;
    compact2[0][1] = c2;
    compact2[0][2] = count2;

    int k2 = 1;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            if (matrix2[i][j] != 0) {
                compact2[k2][0] = i;
                compact2[k2][1] = j;
                compact2[k2][2] = matrix2[i][j];
                k2++;
            }
        }
    }

    cout << "\nCompact form of first matrix:\n";
    for (int i = 0; i < count1 + 1; i++) {
        cout << compact1[i][0] << "\t" << compact1[i][1] << "\t" << compact1[i][2] << "\n";
    }

    cout << "\nCompact form of second matrix:\n";
    for (int i = 0; i < count2 + 1; i++) {
        cout << compact2[i][0] << "\t" << compact2[i][1] << "\t" << compact2[i][2] << "\n";
    }

    return 0;
}
