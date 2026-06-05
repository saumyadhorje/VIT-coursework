#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of unknowns: ";
    cin >> n;

    float a[10][11], x[10];

    cout << "Enter coefficients of augmented matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Forward Elimination
    for (int i = 0; i < n - 1; i++) {
        if (a[i][i] == 0) {
            cout << "Mathematical Error!";
            return 0;
        }

        for (int j = i + 1; j < n; j++) {
            float ratio = a[j][i] / a[i][i];
            for (int k = 0; k <= n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = "
             << fixed << setprecision(3)
             << x[i] << endl;
    }

    return 0;
}