//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=132&page=show_problem&problem=1869
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while(n != 0) {
        int p;
        scanf("%d", &p);
        getchar();
        vector<vector<int>> neighbors(p);
        for(int i = 0; i < p; i++) {
            int j;
            while(1) {
                char c;
                scanf("%d%c", &j, &c);
                neighbors[i].push_back(j);
                if(c == '\n' || c == '\r') {
                    break;
                }
            }
        }
        int best = INT8_MAX;
        vector<int> ideal(p);
        for(int i = 0; i < neighbors.size(); i++) {
            if(neighbors[i].size() == 0)
                continue;
            if(neighbors[i].size() < best) {
                ideal.clear();
                ideal.push_back(i+1);
                best = neighbors[i].size();
            }
            else if(neighbors[i].size() == best) {
                ideal.push_back(i+1);
            }
        }
        for(int i = 0; i < ideal.size(); i++) {
            cout << ideal[i];
            if(i != ideal.size() - 1)
                cout << " ";
        }
        cout << endl;
        n--;
    }
    return 0;
}