#include <iostream>
using namespace std;
class book{
    private:
    int bookId;
     string bookName;
     string author;
     float price;
     public:
     getDetails(){

      cout << "\nEnter Book ID: ";
        cin >> bookId;

        cin.ignore();

        cout << "Enter Book Name: ";
        getline(cin, bookName);

        cout << "Enter Author Name: ";
        getline(cin, author);

        cout << "Enter Price: ";
        cin >> price;
    }

     printDetails() {
        cout << left << setw(10) << bookId
             << setw(25) << bookName
             << setw(20) << author
             << setw(10) << price << endl;
     }
     float get_price(){
        return price;
     }
};
int main(){
int n;
cout<<"enter no of book:"<<endl;
cin>>n;

float total=0;
book b[n];
for(int i=0;i<n;i++){
    cout<<"enter book details"<<i+1<<endl;
    b[i].getDetails;
    cout << "\nBook Details\n";
    cout << "ID\tBook Name\tAuthor\tPrice\n";

    for (int i = 0; i < n; i++)
    {
        b[i].printDetails();
        total = total + b[i].getPrice();
    }

    cout << "\nTotal Price = " << total;
}
    return 0;
}
