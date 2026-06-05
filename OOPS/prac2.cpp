#include <iostream>
using namespace std;
class animal{
    public:
    void makesound(){
        cout<<"animal makes sound"<<endl;
    }
};
class cow:public animal{
    public:
    void makesound(){
        cout<<"moooo"<<endl;
    }
};

class cat:public animal{
    public:
    void makesound(){
        cout<<"cat goes meowww"<<endl;
    }
};
int main(){
animal obj1;
obj1.makesound();
cow obj2;
obj2.makesound();
cat obj3;
obj3.makesound();

    return 0;
}