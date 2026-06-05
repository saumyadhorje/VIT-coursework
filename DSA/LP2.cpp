#include <iostream>
using namespace std;
#define size 12

struct bucket{
    int s1,s2,s3;
};
void init(bucket h[]){
    for(int i=0; i<size;i++){
    h[i].s1=-1;
    h[i].s2=-1;
    h[i].s3=-1;
    }
}
void insertkey(bucket h[], int key){
    int index=key%size;
    //check if slots are empty , if not put key
    if(h[index].s1==-1){
        h[index].s1=key;
        return;
    }
     if(h[index].s2==-1){
        h[index].s2=key;
        return;
    }
     if(h[index].s3==-1){
        h[index].s3=key;
        return;
    }
    int i=(index+1) %size;
   while(i!=index){
    if(h[i].s1==-1){
        h[i].s1=key;
        return;
    }
    if(h[i].s2==-1){
        h[i].s2=key;
        return;
    }
    if(h[i].s3==-1){
        h[i].s3=key;
        return;
    }
 i = (i + 1) % size;
   }
cout<<"table full"<<endl;
}

void display(bucket h[]) {
    for (int i = 0; i < size; i++) {
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
    bucket h[size];
    init(h);

    int key;
    while (true) {
        cout << "\nEnter key (-1 to stop): ";
        cin >> key;
        if (key == -1) break;

        insertkey(h, key);
        display(h);
    }
}