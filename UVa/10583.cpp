//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=133&page=show_problem&problem=1524
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
    int n, m;
    int curCase = 1;
    while(scanf("%d %d\n", &n, &m) == 2) {
        if(n == 0 && m == 0)
            break;
        initSet(n);
        for(int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d\n", &a, &b);
            unionSet(a, b);
        }
        map<int, int> parents;
        for(auto it = pset.begin(); it != pset.end(); it++) {
            parents[findSet(*it)]++;
        }
        printf("Case %d: ", curCase++);
        cout << parents.size() << endl;
    }

    return 0;
}