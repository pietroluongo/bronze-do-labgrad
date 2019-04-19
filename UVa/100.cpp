//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=36
#include <iostream>
#include <cstdio>

int getStepsCount(int val);
int isEven(int n);

int main() {
    int n1, n2;
    while(scanf("%d %d", &n1, &n2) == 2) {
        int max = 0;
        int n3, n4;
        if(n1 > n2) {
            n3 = n2;
            n4 = n1;
        }
        else {
            n3 = n1;
            n4 = n2;
        }
        for(int i = n3; i <= n4; i++) {
            int val = getStepsCount(i);
            if(val > max)
                max = val;
        }

        printf("%d %d %d\n", n1, n2, max);
    }

    return 0;
}

int isEven(int n)
{
    return n % 2 == 0;
}

int getStepsCount(int val) {
    int steps = 0;
    if(val == 1)
        return 1;
    while(val != 1) {
        if(isEven(val)) {
            val = val/2;
        }
        else {
            val = (3 * val) + 1;
        }
        steps++;
    }
    return steps+1;
}
