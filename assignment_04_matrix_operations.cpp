// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// (instructions as given)
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int rowsA, int colsA,
                       int b[MAX_SIZE][MAX_SIZE], int rowsB, int colsB,
                       int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "Matrix Operations Menu:" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        int matrix[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(matrix, rows, cols);
        transposeMatrix(matrix, rows, cols, result);

        cout << endl << "Original Matrix:" << endl;
        printMatrix(matrix, rows, cols);
        cout << endl << "Transposed Matrix:" << endl;
        printMatrix(result, cols, rows);

    } else if (choice == 2) {
        int rows, cols;
        int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << endl << "Enter Matrix A:" << endl;
        readMatrix(a, rows, cols);
        cout << endl << "Enter Matrix B:" << endl;
        readMatrix(b, rows, cols);

        addMatrices(a, b, rows, cols, result);

        cout << endl << "Sum Matrix:" << endl;
        printMatrix(result, rows, cols);

    } else if (choice == 3) {
        int rowsA, colsA, rowsB, colsB;
        int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

        cout << "Enter rows of Matrix A: ";
        cin >> rowsA;
        cout << "Enter columns of Matrix A: ";
        cin >> colsA;

        cout << "Enter rows of Matrix B: ";
        cin >> rowsB;
        cout << "Enter columns of Matrix B: ";
        cin >> colsB;

        if (colsA != rowsB) {
            cout << "Error: Columns of A must equal rows of B for multiplication." << endl;
            return 0;
        }

        cout << endl << "Enter Matrix A:" << endl;
        readMatrix(a, rowsA, colsA);
        cout << endl << "Enter Matrix B:" << endl;
        readMatrix(b, rowsB, colsB);

        multiplyMatrices(a, rowsA, colsA, b, rowsB, colsB, result);

        cout << endl << "Product Matrix (A x B):" << endl;
        printMatrix(result, rowsA, colsB);

    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}