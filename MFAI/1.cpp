#include <iostream>
using namespace std;
int main(){
    int a[3]={1,2,3};
    int b[3]={8,9,7};
    int add[3] , sub[3],mul[3];
    for(int i=0;i<3;i++){
        add[i]=a[i]+b[i];
        sub[i]=a[i]-b[i];
        mul[i]=a[i]*b[i];
        cout<<"mul is:\t"<<mul[i]<<endl;
        cout<<"add is:\t"<<add[i]<<endl;
        cout<<"sub is:\t"<<sub[i]<<endl;
        return 0;
    }
}