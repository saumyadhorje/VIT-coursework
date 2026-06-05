// implement a class Book with suitable data members. Use 
//constructors to initialize book details and a destructor to indicate object destruction, 
//thereby demonstrating the concepts of objects, classes, constructors, and destructors.
#include <iostream>
using namespace std;
class book{
    public:
    int price;
    int id;
    string name;
    void read(){
        cout<<"reading"<<endl;
    }
    book (){
        cout<<"this is a constuctor"<<endl;
    }
    ~book(){
        cout<<"this is a destructor"<<endl;
    }
};
int main(){
book b;
b.id=1;
b.price=1300;
b.name="famous five";
cout<<"book id is:"<<b.id<<endl;
cout<<"book name is:"<<b.name<<endl;
cout<<"book price is:"<<b.price<<endl;
    return 0;

}