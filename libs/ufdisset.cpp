#include <vector>
using namespace std;

// Generic Union-Find Disjoint Set implementation

class UnionFindDisjointSet {
    vector<int> pset;
    public:
    UnionFindDisjointSet(int _size) {
        initSet(_size);
    }

    ~UnionFindDisjointSet();
    
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
}