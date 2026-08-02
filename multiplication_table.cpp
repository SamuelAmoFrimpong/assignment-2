#include <iostream>
using namespace std;

void printTable(int num) {
    cout << "Multiplication Table for " << num << ":" << endl;

    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << i << "  =  " << (num * i) << endl;
    }
}

void printTablesUpToN(int n) {
    for (int i = 1; i <= n; i++) {
        printTable(i);

        if (i < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    printTable(number);

    cout << endl;

    int n;
    cout << "Enter N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    printTablesUpToN(n);

    return 0;
}