#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

// Generic Union-Find Disjoint Set implementation

class UnionFindDisjointSet {
    vector<int> pset;
public:
    UnionFindDisjointSet(int _size) {
        initSet(_size);
    }

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
};


// Max 500 points
struct P {
    int x, y;
}points[501];

// Max 501² edges
struct E {
    int p1;
    int p2;
    double w;
}edges[501 * 501];

bool cmpFunc(const E &a, const E &b) {
    return a.w < b.w;
}


int edgeCount;

int main() {
    int caseCount;
    scanf("%d", &caseCount);
    while(caseCount--) {
        for(int i = 0; i < 501; i++) {
            points[i] = {0,0};
        }
        for(int i = 0; i < 501*501; i++) {
            edges[i] = {0, 0, 0};
        }
        UnionFindDisjointSet set = UnionFindDisjointSet(501);
        int s, p;
        scanf("%d %d", &s, &p);
        for(int i= 0; i < p; i++) {
            scanf("%d %d", &points[i].x, &points[i].y);
        }
        edgeCount = 0;
        for(int i = 0; i < p; i++) {
            for(int j = i; j < p; j++) {
                double L = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
                edges[edgeCount++] = {i, j, L};
            }
        }
        sort(edges, edges+edgeCount, cmpFunc);
        vector<double> EdgeLen;
        int eCount = 0;
        for(int i = 1; eCount != p-1; i++) {
            if(!set.isSameSet(edges[i].p1, edges[i].p2)) {
                set.unionSet(edges[i].p1, edges[i].p2);
                EdgeLen.push_back(edges[i].w);
                eCount++;
            }
        }
        printf("%.2f\n", EdgeLen[p-s-1]);
    }
}