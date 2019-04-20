#include <vector>
using namespace std;

// Segment Tree implementation - based on https://github.com/stevenhalim/cpbook-code/blob/master/ch2/segmenttree_ds.cpp

class SegTree {
private:
    vector<int> st, A;
    int left(int p) {
        return p<<1;
    }
    
    int right(int p) {
        return (p<<1)+1;
    }

    // Builds tree recursively
    void build(int p, int L, int R) {
        // Stop condition
        if(L == R)
            // Index (of what???)
            st[p] = L;
        else {
            // Build tree recursively
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2+1, R);
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j) {
        // Segment outside query range
        if(i > R || j < L)
            return -1;
        // Segment inside query range
        if(L >= i && R <= j)
            return st[p];
        // Compute min pos on left and right interval edges
        int p1 = rmq(left(p), L, (L+R)/2, i, j);
        int p2 = rmq(right(p), (L+R)/2+1, R, i, j);
        // If segment is outside query range
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] <= A[p2] ? p1 : p2);
    }

    int update(int p, int L, int R, int idx, int new_val) {
        int i = idx;
        int j = idx;

        // If current interval won't intersect with update range
        if(i > R || j < L) return st[p];
        // If current interval is included in update range
        if(L==i && R==j) {
            // Update array
            A[i] = new_val;
            return st[p] = L;
        }
        int p1, p2;
        p1 = update(left(p), L, (L+R)/2, idx, new_val);
        p2 = update(right(p), (L+R)/2+1, R, idx, new_val);
        // Return the position where the overall minimum is
        // Edit this part if you need to change the comparing function!
        return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }

    public:
    SegTree(const vector<int>& _A) {
        this->A = _A;
        st.assign(4*A.size(), 0);
        build(1, 0, A.size()-1);
    }
    
    // Range minimum query
    int rmq(int i, int j) {
        return rmq(1, 0, A.size()-1, i, j);
    }
    
    // Update tree data
    int update(int i, int v) {
        return update(1, 0, A.size()-1, i, v);
    }
};