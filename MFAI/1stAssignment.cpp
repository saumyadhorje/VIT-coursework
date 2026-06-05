#include <iostream>
#include <vector>
using namespace std;

int main() {
    int choice;
    cout << "1. Vector Operations\n";
    cout << "2. 2D Matrix Operations \n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {

    // vector
    case 1: {
        vector<int> a = {1, 2, 3};
        vector<int> b = {8, 9, 7};

        cout << "\nVector Answers:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Index " << i << " -> ";
            cout << "Add = " << a[i] + b[i] << ", ";
            cout << "Sub = " << a[i] - b[i] << ", ";
            cout << "Mul = " << a[i] * b[i] << endl;
        }
        break;
    }

    //  matrix
    case 2: {
        int a[2][2] = {{1, 2}, {3, 4}};
        int b[2][2] = {{4, 5}, {6, 7}};
        int sum, diff, product;

        cout << "\nMatrix Element-wise Answers:\n";

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {

                sum = a[i][j] + b[i][j];
                diff = a[i][j] - b[i][j];

                
                product = 0;
                for (int k = 0; k < 2; k++) {
                    product += a[i][k] * b[k][j];
                }

                cout << "Position (" << i << "," << j << ") -> ";
                cout << "Add = " << sum
                     << ", Sub = " << diff
                     << ", Mul = " << product << endl;
            }
        }

        break;
    }

    default:
        cout << "Invalid choice!";
    }

    return 0;
}
