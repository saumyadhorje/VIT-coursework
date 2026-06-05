#include <iostream>
#include <stack>
using namespace std;

int precedence(char c){
    if(c=='*'||c=='/')return 2;
    else if(c=='+'|| c=='-')return 1;
    return 0;
}
string InfixToPostfix(string s){
    stack<char>st;
    string res="";
    for(char c:s){
        //if operand
        if(isalnum(c)){
            res+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty()&&st.top()!='('){
                st.pop();
                res+=st.top();
            }
            st.pop();
        }
        else//operator
        {
            while(!st.empty()&&precedence(st.top())>=precedence(c)){
                res+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
     while (!st.empty()) {          // leftover operators
        res += st.top();
        st.pop();
    }
    return res;
}
int main(){
    string s;
    cout<<"enter string :";
    cin>>s;
    cout<<InfixToPostfix(s);
    return 0;
}