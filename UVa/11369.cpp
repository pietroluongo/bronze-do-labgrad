// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=140&page=show_problem&problem=2354
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_ITEMS 20000

int main() {
    int test_cases;
    cin >> test_cases;
    for(int i = 0; i < test_cases; i++) {
        int item_count;
        vector<int> prices;
        scanf("%d", &item_count);
        prices.resize(item_count);
        for(int i = 0; i < item_count; i++) {
            scanf("%d", &prices[i]);
        }
        sort(prices.begin(), prices.end());
        int discount = 0;
        for(int i = item_count - 3; i >= 0; i -= 3) {
            discount += prices[i];
        }
        cout << discount << endl;
    }
    return 0;
}