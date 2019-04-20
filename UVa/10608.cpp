//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=133&page=show_problem&problem=1549
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> pset(1000);
void initSet(int _size) {
    pset.resize(_size);
    for(int i = 0; i <= (_size - 1); i++) {
        pset[i] = i;
    }
}

int findSet(int i) {
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}

void unionSet(int i, int j) {
    pset[findSet(i)] = findSet(j);
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

int main() {
    int cases = 0;
    scanf("%d\n", &cases);
    while(cases--) {
        int n, m;
        scanf("%d %d\n", &n, &m);
        initSet(n);
        while(m--) {
            int a, b;
            scanf("%d %d\n", &a, &b);
            unionSet(a, b);
        }
        map<int, int> friends;
        for(auto it = pset.begin(); it != pset.end(); it++) {
            friends[findSet(*it)]++;
        }
        int biggest = 0;
        for(auto it = friends.begin(); it != friends.end(); it++){
            if(it->second >= biggest)
                biggest = it->second;
        }
        cout << biggest << endl;
    }
    return 0;
}