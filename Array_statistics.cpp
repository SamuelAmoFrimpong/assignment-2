#include <iostream>
using namespace std;

int getSum(int arr[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }

    return sum;
}

double getAverage(int arr[], int n) {
    int sum = getSum(arr, n);
    double average = (double)sum / n;
    return average;
}

int getMax(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int getMin(int arr[], int n) {
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    int numbers[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    int sum = getSum(numbers, n);
    double average = getAverage(numbers, n);
    int maximum = getMax(numbers, n);
    int minimum = getMin(numbers, n);

    cout << endl;
    cout << "Results:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;

    return 0;
}