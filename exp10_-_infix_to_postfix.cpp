#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to determine precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix;
    
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) {
                s.pop();
            }
        }
    }
    
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> s;
    
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else if (isOperator(ch)) {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            
            switch (ch) {
                case '+':
                    s.push(val1 + val2);
                    break;
                case '-':
                    s.push(val1 - val2);
                    break;
                case '*':
                    s.push(val1 * val2);
                    break;
                case '/':
                    s.push(val1 / val2);
                    break;
            }
        }
    }
    
    return s.top();
}

int main() {
    string infix;
    cout << "Enter an infix expression (single character operands and +, -, *, / operators only): ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result of evaluation: " << result << endl;

    return 0;
}
