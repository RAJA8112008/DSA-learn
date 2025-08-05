#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Check if character is operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Operator precedence (ignoring associativity)
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Convert infix to postfix
string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for (char c : s) {
        if (isalnum(c)) {
            // If operand, add to result
            result += c;
        } 
        else if (c == '(') {
            st.push(c);
        } 
        else if (c == ')') {
            // Pop until matching '('
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // pop '('
        } 
        else if (isOperator(c)) {
            // Pop while stack top has higher or equal precedence
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
            
        }
    }

    // Pop any remaining operators
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
