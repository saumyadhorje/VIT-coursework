#include <iostream>
using namespace std;

int binarySearch(int arr[], int n , int target){
    int l=0;
    int r=n-1;
    int mid=(l+r)/2;
    while(l<=r){
        if(target==arr[mid]) return mid;
        else if(target>arr[mid]) l=mid+1;
        else{
            r=mid-1;
        }
    }
return -1;
}

void printArray(int arr[] , int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
            int target;
            cout << "Enter target to search: ";
            cin >> target;
            int result = binarySearch(arr, n, target);
            if(result != -1)
                cout << "Element found at index " << result << endl;
            else
                cout << "Element not found\n";
        }
        else if(choice == 3){
            printArray(arr, n);
        }

    } while(choice != 4);

    return 0;
}