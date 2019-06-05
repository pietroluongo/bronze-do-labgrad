// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=140&page=show_problem&problem=1995
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_HOUSES 100000

int main() {
    int n;
    while (cin >> n && n) {
        vector<int> houses(n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &houses[i]);
        }
        unsigned long long int distsum = 0;
        for(int i = 1; i < n; i++) {
            houses[i] += houses[i-1];
            distsum += abs(houses[i-1]);
        }
        cout << distsum << endl;
    }
    return 0;
}
