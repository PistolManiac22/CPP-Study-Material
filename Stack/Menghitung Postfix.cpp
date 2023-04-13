#include <iostream>
#include <stack>
#include <string>
#include <regex>

using namespace std;

int prioritas(char operand) {
    if (operand == '(' || operand == ')') {
        return 0;
    } else if (operand == '+' || operand == '-') {
        return 1;
    } else if (operand == '*' || operand == '/') {
        return 2;
    } else if (operand == '^') {
        return 3;
    } else {
        return -1;
    }
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    regex r("\\s+");
    infix = regex_replace(infix, r, "");

    for (int i = 0; i < infix.length(); i++) {
        if (isalpha(infix[i]) || isdigit(infix[i])) {
            postfix += infix[i];
        } else if (infix[i] == '(') {
            s.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop();
            } else {
                return "Invalid infix";
            }
        } else {
            while (!s.empty() && prioritas(infix[i]) <= prioritas(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }

    while (!s.empty()) {
        if (s.top() == '(' || s.top() == ')') {
            return "Invalid infix";
        }
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string input;
    cout << "Masukkan infix yang ingin diubah menjadi postfix : ";
    getline(cin, input);
    cout << "Hasil postfix : " << infixToPostfix(input) << endl;
    return 0;
}
