#include <iostream>
using namespace std;

#define SIZE 11    // no semicolon here!

int table1[SIZE], table2[SIZE];

// hash functions
int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return (key / SIZE) % SIZE;
}

// initialize tables
void init() {
    for(int i = 0; i < SIZE; i++) {
        table1[i] = -1;
        table2[i] = -1;
    }
}

// insert key
void insertkey(int key) {
    int currentkey = key;
    int tableno = 1;

    // try at most SIZE times (prevents infinite loop)
    for(int count = 0; count < SIZE; count++) {

        if(tableno == 1) {
            int pos = hash1(currentkey);

            if(table1[pos] == -1) {     // empty slot found
                table1[pos] = currentkey;
                return;
            } else {
                // kick out old key
                swap(currentkey, table1[pos]);
                tableno = 2;            // move to table2
            }
        }

        else {  // tableno == 2
            int pos = hash2(currentkey);

            if(table2[pos] == -1) {     // empty slot found
                table2[pos] = currentkey;
                return;
            } else {
                // kick out old key
                swap(currentkey, table2[pos]);
                tableno = 1;            // move back to table1
            }
        }
    }

    cout << "Rehash needed for key " << key << "!\n";
}

// print tables
void printTables() {
    cout << "Table 1: ";
    for(int i = 0; i < SIZE; i++)
        cout << table1[i] << " ";

    cout << "\nTable 2: ";
    for(int i = 0; i < SIZE; i++)
        cout << table2[i] << " ";

    cout << endl;
}

int main() {
    init();

    int keys[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};

    for(int key : keys)
        insertkey(key);

    printTables();
}
