// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=137&page=show_problem&problem=382
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int k;
    bool flag = false;
    while(scanf("%d", &k) == 1 && k) {
        if(flag)
            printf("\n");
        flag = true;
        vector<int> nums;
        nums.reserve(k);
        for(int i = 0; i < k; i++) {
            scanf("%d", &nums[i]);
        }
        for(int a = 0; a < k - 5; a++) {
            for(int b = a + 1; b < k - 4; b++) {
                for(int c = b + 1; c < k - 3; c++) {
                    for(int d = c + 1; d < k - 2; d++) {
                        for(int e = d + 1; e < k - 1; e++) {
                            for(int f = e + 1; f < k; f++) {
                                printf("%d %d %d %d %d %d\n", nums[a], nums[b], nums[c], nums[d], nums[e], nums[f]);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}