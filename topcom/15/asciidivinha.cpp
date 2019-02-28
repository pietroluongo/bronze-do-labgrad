#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

bool ehNumero(char c) {
    return '0' <= c && '9' >= c;
}

int main() {
    char c;
    while(scanf("%c", &c) == 1) {
        if (ehNumero(c)) {
            char c2, c3;
            scanf("%c%c", &c2, &c3);
            string s = "";
            s += c;
            s += c2;
            s += c3;
            int n = stoi(s);
            printf("%c", (char) n);
        } else if (c == '(' || c == ')') {
            int n;
            scanf("%d)", &n);
            printf("%d", n);
        } else {
            printf("%c", c);
        }
    }
    return 0;
}