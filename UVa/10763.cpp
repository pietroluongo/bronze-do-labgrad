// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=140&page=show_problem&problem=1704
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_SIZE 500001

int main() {
    vector<int> a, b;
    int candCount;
    while(cin >> candCount && candCount) {
        a.clear();
        b.clear();
        a.reserve(candCount);
        b.reserve(candCount);
        for(int i = 0; i < candCount; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            a.push_back(x);
            b.push_back(y);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool failed = false;
        while(a.size() > 0 && !failed) {
            if(a.back() == b.back()) {
                a.pop_back();
                b.pop_back();
            }
            else
                failed = true;
        }
        if(failed)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}