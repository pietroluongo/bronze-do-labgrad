//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=121&problem=882
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

// Needs further optimization

#define NORMAL true
#define REVERSED false

typedef unsigned long long bignum;
typedef bool direction;


bignum fatorial(bignum in);

int main() {
    int samples;
    cin >> samples;
    for(int i = 0; i < samples; i++) {
        direction dir = NORMAL;
        string input;
        cin >> input;
        bignum perm_count;
        cin >> perm_count;
        sort(input.begin(), input.end());
        bignum max = fatorial(input.length());
        // If it is closer to the endpoint than the starting point
        if(max - perm_count < perm_count) {
            // Invert and make it permute backwards
            reverse(input.begin(), input.end());
            perm_count = max - perm_count - 1;
            dir = REVERSED;
        }
        if(dir == NORMAL) {
            for (bignum j = 0; j < perm_count; j++) {
                next_permutation(input.begin(), input.end());
            }
        } else if(dir == REVERSED) {
            for (bignum j = 0; j < perm_count; j++) {
                prev_permutation(input.begin(), input.end());
            }
        }
        cout << input << endl;
    }
    return 0;
}

bignum fatorial(bignum in) {
    if(in == 0)
        return 1;
    return in * fatorial(in - 1);
}