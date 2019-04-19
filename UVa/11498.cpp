// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=2493
#include <iostream>

using namespace std;

int main() {
    int queries;
    while(scanf("%d\n", &queries) == 1) {
        if(queries == 0)
            break;
        int div_x, div_y;
        scanf("%d %d\n", &div_x, &div_y);
        for(int i = 0; i < queries; i++) {
            int x, y;
            scanf("%d %d\n", &x, &y);
            if(x == div_x || y == div_y) {
                cout << "divisa" << endl;
            }
            else if(x > div_x && y > div_y) {
                cout << "NE" << endl;
            } 
            else if(x > div_x && y < div_y) {
                cout << "SE" << endl;
            } else if(x < div_x && y < div_y) {
                cout << "SO" << endl;
            } else if(x < div_x && y > div_y) {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}