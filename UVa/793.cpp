//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=133&page=show_problem&problem=734
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class UnionFindDisjointSet {
    vector<int> pset;
    public:
    UnionFindDisjointSet(int _size) {
        initSet(_size);
    }

    ~UnionFindDisjointSet() {

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

int main() {
    int cases;
    scanf("%d", &cases);
    getchar();
    while(cases--) {
        int computer_count;
        scanf("%d", &computer_count);
        getchar();
        UnionFindDisjointSet network = UnionFindDisjointSet(computer_count);
        int successful_requests = 0, failed_requests = 0;
        while(1) {
            char op;
            int a, b;
            scanf("%c ", &op);
            if(op == '\n') {
                break;
            }
            scanf("%d %d", &a, &b);
            char s = getchar();
            if(s == EOF) {break;}
            if(op == 'c') {
                network.unionSet(a-1, b-1);
            }
            else if(op == 'q') {
                if(network.isSameSet(a-1, b-1))
                    successful_requests++;
                else
                    failed_requests++;
            }
        }
        printf("%d,%d\n", successful_requests, failed_requests);
        if(cases != 0)
            cout << endl;
    }
    return 0;
}