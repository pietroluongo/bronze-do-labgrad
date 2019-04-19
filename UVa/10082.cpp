//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=1023
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool findAndPrint(vector<char> v, char tgt);

int main() {
    vector<char> row_a = {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='};
    vector<char> row_b = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'};
    vector<char> row_c = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\''};
    vector<char> row_d = {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'};
    char c;
    while(scanf("%c", &c) == 1) {
        if(findAndPrint(row_a, c))
            continue;
        else if(findAndPrint(row_b, c))
            continue;
        else if(findAndPrint(row_c, c))
            continue;
        else if(findAndPrint(row_d, c))
            continue;
        else
            printf("%c", c);
    }


    return 0;
}

bool findAndPrint(vector<char> v, char tgt) {
    vector<char>::iterator it = find(v.begin(), v.end(), tgt);
    if(it != v.end()) {
        prev(it);
        char c = v[distance(v.begin(), it)-1];
        printf("%c", c);
        return true;
    }
    return false;
}