#include <iostream>
using namespace std;
#include <stack>
#include <queue>


void reversestack(stack<int>&st){
    queue<int>q;
    //move from stack to queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);

    reversestack(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}