#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to convert postfix to infix
string postfixToInfix(string s) {
    stack<string> st;   // stack to store intermediate expressions

    // Traverse each character in the postfix expression
    for (char ch : s) {

        // If the character is an operand (A-Z, a-z, 0-9), push it directly
        if (isalnum(ch)) {
            st.push(string(1, ch));  // convert char to string and push
        }
        else {
            // ch is an operator (+, -, *, /, etc.)
            
            // Pop the top two operands from the stack
            string b = st.top(); 
            st.pop();

            string a = st.top(); 
            st.pop();

            // Form the infix expression: (a operator b)
            string temp = "(" + a + ch + b + ")";

            // Push the new combined expression back to the stack
            st.push(temp);
        }
    }

    // Final element in the stack is the complete infix expression
    return st.top();
}

int main() {
    string postfix;

    // Input postfix expression
    cout << "Enter postfix: ";
    cin >> postfix;

    // Output the converted infix expression
    cout << "Infix: " << postfixToInfix(postfix);

    return 0;
}
