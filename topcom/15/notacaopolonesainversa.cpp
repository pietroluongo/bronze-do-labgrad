#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>

using namespace std;

bool isOp(string c) {
    return c == "+" || c == "-" || c == "/" || c == "*";
}

int doOperation(string op, string n1, string n2) {
    int num1 = stoi(n1);
    int num2 = stoi(n2);
    if(op == "+")
        return num1 + num2;
    if(op == "-")
        return num1 - num2;
    if(op == "/")
        return num1 / num2;
    if(op == "*")
        return num1 * num2;
    return 0;
}

string topNPop(stack<string>* s) {
    string r = s->top();
    s->pop();
    return r;
}

bool processStack(stack<string>* s) {
    string a, b, op;
    op = topNPop(s);
    b = topNPop(s);
    a = topNPop(s);
    if(op == "/" && b == "0")
        return false;
    s->push(to_string(doOperation(op, a, b)));
    return true;
}

int main() {
    int expr_count;
    scanf("%d\n", &expr_count);
    for(int i = 0; i < expr_count; i++) {
        stack<string> op_stack;
        string line;
        getline(cin, line);
        char c_line[9999];
        strcpy(c_line, line.c_str());
        char c[9999];
        int n = 0;
        bool hasDividedByZero = false;
        while(sscanf(c_line + n, "%s ", c) == 1) {
            if(n > line.length())
                break;
            string s = c;
            n += s.length() + 1;
            op_stack.push(s);
            if(isOp(s)){
                if(!processStack(&op_stack)) {
                    cout << "DIV0" << endl;
                    hasDividedByZero = true;
                    continue;
                }
            }
        }
        if(!hasDividedByZero)
            cout << op_stack.top() << endl;
    }
    return 0;
}