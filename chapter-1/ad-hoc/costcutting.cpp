// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=2827
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int cases;
    scanf("%d\n", &cases);
    for(int i = 0; i < cases; i++) {
        int val[3];
        for(int j = 0; j < 3; j++) {
            scanf("%d ", &val[j]);
        }
        sort(val, val+3);
        cout << "Case " << i+1 << ": " << val[1] << endl;

    }
    return 0;
}