//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=132&page=show_problem&problem=227
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int adj[5][5] = {
    {0,1,1,0,1},
    {1,0,1,0,1},
    {1,1,0,1,1},
    {0,0,1,0,1},
    {1,1,1,1,0}
};

int out[8] = {0};

void DFS(int idx, int cur) {
    out[idx] = cur;
    if(idx == 8) {
        for(int i = 0; i < 9; i++) {
            printf("%d", out[i]+1);
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < 5; i++) {
        if(adj[cur][i] == 1) {
            // Disconnect node
            adj[cur][i] = adj[i][cur] = 0;
            // Recursive call
            DFS(idx+1, i);
            // Reconnect node
            adj[cur][i] = adj[i][cur] = 1;
        }
    }
}

int main() {
    DFS(0, 0);
    return 0;
}