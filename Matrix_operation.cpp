#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void inputMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void displayMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int mat[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum = sum + a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int matA[10][10];
    int matB[10][10];
    int result[10][10];
    int rows, cols;

    // -------------------------------
    // PART A - Transpose a Matrix
    // -------------------------------
    cout << "PART A - Transpose a Matrix" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    inputMatrix(matA, rows, cols);

    cout << endl << "Original Matrix:" << endl;
    displayMatrix(matA, rows, cols);

    transposeMatrix(matA, result, rows, cols);

    cout << endl << "Transposed Matrix:" << endl;
    displayMatrix(result, cols, rows);

    // -------------------------------
    // PART B - Add Two Matrices
    // -------------------------------
    cout << endl << "PART B - Add Two Matrices" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter values for Matrix A:" << endl;
    inputMatrix(matA, rows, cols);

    cout << "Enter values for Matrix B:" << endl;
    inputMatrix(matB, rows, cols);

    addMatrices(matA, matB, result, rows, cols);

    cout << endl << "Sum Matrix:" << endl;
    displayMatrix(result, rows, cols);

    // -------------------------------
    // PART C - Multiply Two Matrices
    // -------------------------------
    int m, n, n2, p;

    cout << endl << "PART C - Multiply Two Matrices" << endl;
    cout << "Enter rows of Matrix A: ";
    cin >> m;
    cout << "Enter columns of Matrix A: ";
    cin >> n;

    cout << "Enter values for Matrix A:" << endl;
    inputMatrix(matA, m, n);

    cout << "Enter rows of Matrix B: ";
    cin >> n2;
    cout << "Enter columns of Matrix B: ";
    cin >> p;

    if (n2 != n) {
        cout << "Error: Number of columns in A must equal number of rows in B." << endl;
        return 0;
    }

    cout << "Enter values for Matrix B:" << endl;
    inputMatrix(matB, n2, p);

    multiplyMatrices(matA, matB, result, m, n, p);

    cout << endl << "Product Matrix (A x B):" << endl;
    displayMatrix(result, m, p);

    return 0;
}