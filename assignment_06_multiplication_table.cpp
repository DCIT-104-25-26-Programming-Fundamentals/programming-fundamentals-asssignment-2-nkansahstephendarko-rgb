// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// (instructions as given)
//

#include <iostream>
using namespace std;

void printTable(int number) {
    cout << "Multiplication Table for " << number << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << number << " x " << i << " = " << (number * i) << endl;
    }
}

void printTablesUpTo(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    for (int num = 1; num <= n; num++) {
        printTable(num);
        if (num != n) {
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
    cout << "Enter N (for tables 1 to N): ";
    cin >> n;
    printTablesUpTo(n);

    return 0;
}