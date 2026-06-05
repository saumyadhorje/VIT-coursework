#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, c, d;
    float trace, determinant, discriminant;
    float lambda1, lambda2;

    // Input matrix
    cout << "Enter elements of 2x2 matrix:\n";
    cout << "a b\nc d\n";
    cin >> a >> b >> c >> d;

    // Trace and determinant
    trace = a + d;
    determinant = (a * d) - (b * c);

    // Discriminant
    discriminant = trace * trace - 4 * determinant;

    if (discriminant < 0) {
        cout << "\nEigenvalues are complex.\n";
        return 0;
    }

    // Eigenvalues
    lambda1 = (trace + sqrt(discriminant)) / 2;
    lambda2 = (trace - sqrt(discriminant)) / 2;

    cout << "\nEigenvalues are:\n";
    cout << "Lambda 1 = " << lambda1 << endl;
    cout << "Lambda 2 = " << lambda2 << endl;

    // Eigenvectors
    cout << "\nEigenvector corresponding to Lambda 1:\n";
    cout << "(" << -b << ", " << a - lambda1 << ")\n";

    cout << "\nEigenvector corresponding to Lambda 2:\n";
    cout << "(" << -b << ", " << a - lambda2 << ")\n";

    return 0;
}
