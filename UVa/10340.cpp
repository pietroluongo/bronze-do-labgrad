// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1281
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

#define MAX_SIZE 1000000

int main() {
    char c_code[MAX_SIZE];
    char c_msg[MAX_SIZE];
    while(scanf("%s %s\n", c_code, c_msg) == 2) {
        int iCode = 0, iMsg = 0;
        int hits = 0;
        while(1) {
            if(c_msg[iMsg] == '\0')
                break;
            if(c_code[iCode] == c_msg[iMsg]) {
                hits++;
                iCode++;
            }
            iMsg++;
        }
        // If hits is code.length, then we have found all elements of the code inside the message
        // That is, it is "encoded"
        if(hits == strlen(c_code))
            cout << "Yes" << endl;
        // Otherwise the code is not inside the message!
        else
            cout << "No" << endl;
    }
    return 0;
}