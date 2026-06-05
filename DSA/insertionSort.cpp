#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        int temp = arr[i];

        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[100];
    int n, choice;

    do {
        cout << "\n1. Read\n2. Sort\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements:\n";
            for(int i = 0; i < n; i++)
                cin >> arr[i];
        }
        else if(choice == 2){
            insertionSort(arr, n);
            cout << "Sorted!\n";
        }
        else if(choice == 3){
            printArray(arr, n);
        }

    } while(choice != 4);

    return 0;
}
