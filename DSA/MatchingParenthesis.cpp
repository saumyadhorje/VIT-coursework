#include <iostream>
#include <stack>
using namespace std;

bool isMatching(string s) {
    stack<char> st;

    for (char c : s) {

        // Push opening brackets
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
         
        // Check closing brackets
        else if (c == ')' || c == '}' || c == ']') {

            if (st.empty()) return false;  // no opening bracket

            char top = st.top();
            st.pop();

            if ( (c == ')' && top != '(') ||
                 (c == '}' && top != '{') ||
                 (c == ']' && top != '[') )
                return false;
        }
    }

    return st.empty();  // stack should be empty at end
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    if (isMatching(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
}
