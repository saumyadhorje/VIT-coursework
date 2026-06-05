#include<iostream>
using namespace std;
int main(){
    int a[2][2]={{1,2},{3,4}};
    int b[2][2]={{4,5},{6,7}};
    int add[2][2] , sub[2][2];
    int trans[2][2] , mul[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            add[i][j]=a[i][j]+b[i][j];
            sub[i][j]=a[i][j]+b[i][j];
            mul[i][j]==0;
            for(int k=0;k<2;k++){
                mul[i][j]=a[i][k]*b[k][j];
            }
            trans[j][i]=a[i][j];
            trans[j][i]=b[i][j];
            cout<<"trans of a is:\t"<<trans[j][i]<<endl;
            cout<<"trans of b is:\t"<<trans[j][i]<<endl;
            cout<<"mul is:\t"<<mul[i][j]<<endl;
            cout<<"sub is:\t"<<sub[i][j]<<endl;
            cout<<"add is:\t"<<add[i][j]<<endl;
            
            return 0;
        }
    }
}