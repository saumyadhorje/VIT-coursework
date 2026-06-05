#include <iostream>
using namespace std;

#define SIZE 11

// each index has 2 slots
struct bucket {
    int s1, s2;
};

// initialize table
void init(bucket h[]) {
    for (int i = 0; i < SIZE; i++) {
        h[i].s1 = -1;
        h[i].s2 = -1;
    }
}

// insert with linear probing
void insertKey(bucket h[], int key) {
    int index = key % SIZE;

    // slot 1 empty
    if (h[index].s1 == -1) {
        h[index].s1 = key;
        return;
    }

    // slot 2 empty
    if (h[index].s2 == -1) {
        h[index].s2 = key;
        return;
    }

    // both full → linear probing
    int i = (index + 1) % SIZE;
    while (i != index) {
        if (h[i].s1 == -1) {
            h[i].s1 = key;
            return;
        }
        if (h[i].s2 == -1) {
            h[i].s2 = key;
            return;
        }
        i = (i + 1) % SIZE;
    }

    cout << "Table is full!\n";
}

// display table
void display(bucket h[]) {
    for (int i = 0; i < SIZE; i++) {
       cout << i << ": [ ";

        if (h[i].s1 == -1) 
            cout << "_";
        else 
            cout << h[i].s1;

        cout << " , ";

        if (h[i].s2 == -1) 
            cout << "_";
        else 
            cout << h[i].s2;

        cout << " ]\n";
    }
}

   

int main() {
    bucket h[SIZE];
    init(h);

    int key;
    while (true) {
        cout << "\nEnter key (-1 to stop): ";
        cin >> key;
        if (key == -1) break;

        insertKey(h, key);
        display(h);
    }
}
