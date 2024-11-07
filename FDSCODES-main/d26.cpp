/*Name: Husain Siamwala
Class: SE2
Roll Number: 76
PRN Number: F24122001

Problem Statement
: In any language program mostly syntax error occurs due to unbalancing
delimiter such as (), {}, []. Write C++ program using stack to check whether given expression is well
parenthesized or not. 
*/

#include <iostream>
#include <stack>
using namespace std;

bool isWellParenthesized(string expression) {
    stack<char> s;
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;
    if (isWellParenthesized(expression)) {
        cout << "The expression is well parenthesized." << endl;
    } else {
        cout << "The expression is not well parenthesized." << endl;
    }
    return 0;
}

/*

Output
Enter an expression: ({[]})
The expression is well parenthesized.
Enter an expression: (){[}]
The expression is not well parenthesized.

*/
