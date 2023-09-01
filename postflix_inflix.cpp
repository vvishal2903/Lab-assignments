#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return -1;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

bool isOperand(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

string infixToPostfix(const string& expression) {
    stack<char> process;
    string result;

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (isOperand(ch)) {  // Operand
            result += ch;
        } else if (ch == '(') {  // Left parenthesis
            process.push(ch);
        } else if (ch == ')') {  // Right parenthesis
            while (!process.empty() && process.top() != '(') {
                result += process.top();
                process.pop();
            }
            if (!process.empty() && process.top() == '(') {
                process.pop();
            }
        } else if (isOperator(ch)) {  // Operator
            while (!process.empty() && precedence(ch) <= precedence(process.top())) {
                result += process.top();
                process.pop();
            }
            process.push(ch);
        }
    }

    while (!process.empty()) {
        result += process.top();
        process.pop();
    }

    return result;
}

int main() {
    string expression;
    cout << "Enter the expression:" << endl;
    getline(cin, expression); // Read the entire expression including spaces
    string postfixExpression = infixToPostfix(expression);

    cout << "Postfix Expression: " << postfixExpression << endl;

    return 0;
}
