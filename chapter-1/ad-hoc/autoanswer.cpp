// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=2542
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int test_cases;
    scanf("%d\n", &test_cases);
    for(int i = 0; i < test_cases; i++) {
        int n;
        scanf("%d", &n);
        n *= 567;
        n = n / 9;
        n += 7492;
        n *= 235;
        n /= 47;
        n -= 498;
        cout << abs(((n%100)/10)) << endl;
    }
    return 0;
}