#include <iostream>
using namespace std;

class Publication
{
protected:
    string title;
    float price;
    int copies;

public:
    void getData()
    {
        cout << "Enter title: ";
        cin >> title;

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter number of copies: ";
        cin >> copies;
    }

    float saleCopy()
    {
        return price * copies;
    }
};

class Book : public Publication
{
    string author;

public:
    void getBookData()
    {
        getData();

        cout << "Enter author name: ";
        cin >> author;
    }

    void orderCopies()
    {
        cout << "Copies ordered for book: " << copies << endl;
    }
};

class Magazine : public Publication
{
public:
    void getMagazineData()
    {
        getData();
    }

    void orderQty()
    {
        cout << "Order quantity: " << copies << endl;
    }

    void currentIssue()
    {
        cout << "Current issue received." << endl;
    }

    void receiveIssue()
    {
        cout << "New magazine issue received." << endl;
    }
};

int main()
{
    Book b;
    Magazine m;

    float totalSales;

    cout << "\nEnter Book Details\n";
    b.getBookData();

    cout << "\nEnter Magazine Details\n";
    m.getMagazineData();

    cout << "\nBook Information\n";
    b.orderCopies();

    totalSales = b.saleCopy() + m.saleCopy();

    cout << "\nTotal sales of all publications: "
         << totalSales << endl;

    return 0;
}