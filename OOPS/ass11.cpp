#include <iostream>
using namespace std;

class book {
public:
    int price;
    string name;

    void getdata() {
        cout << "Enter book name: " << endl;
        cin >> name;

        cout << "Enter price: " << endl;
        cin >> price;
    }

    void display() {
        cout << "Book details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {

    int n;

    cout << "Enter number of books: " << endl;
    cin >> n;

    // Dynamic memory allocation
    book* books = new book[n];

    cout << "Enter book details:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Book " << i + 1 << endl;
        books[i].getdata();
    }

    cout << "\nBook details:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nBook " << i + 1 << endl;
        books[i].display();
    }

    // Free memory
    delete[] books;

    return 0;
}