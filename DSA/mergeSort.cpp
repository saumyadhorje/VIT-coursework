#include <iostream>
using namespace std;

int temp[100];   // helper array for merging

// Merge two sorted halves
void mergeParts(int a[], int left, int mid, int right) {

    int i = left;       // pointer for left half
    int j = mid + 1;    // pointer for right half
    int k = left;       // pointer for temp[]

    // pick smaller element from both halves
    while (i <= mid && j <= right) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    // copy leftover from left half
    while (i <= mid)
        temp[k++] = a[i++];

    // copy leftover from right half
    while (j <= right)
        temp[k++] = a[j++];

    // copy back to original array
    for (int p = left; p <= right; p++)
        a[p] = temp[p];
}

// Merge Sort function
void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);       // sort left part
        mergeSort(a, mid + 1, right);  // sort right part
        mergeParts(a, left, mid, right); // merge them
    }
}

// Display array
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Menu-driven main program
int main() {
    int a[100], n = 0, choice;

    do {
        cout << "\n1. Read\n2. Sort\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter how many numbers: ";
            cin >> n;
            cout << "Enter numbers:\n";
            for (int i = 0; i < n; i++)
                cin >> a[i];
        }

        else if (choice == 2) {
            if (n == 0) cout << "Read numbers first!\n";
            else {
                mergeSort(a, 0, n - 1);
                cout << "Sorted!\n";
            }
        }

        else if (choice == 3) {
            if (n == 0) cout << "Array empty!\n";
            else display(a, n);
        }

    } while (choice != 4);

    return 0;
}
