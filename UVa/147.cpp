// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=143&page=show_problem&problem=293
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define ulli unsigned long long int

// Mults 5
#define MAX_DATA_SIZE 30001

int main() {
    //int coins[11] = {5, 10, 25, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    int coins[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

    ulli dados[MAX_DATA_SIZE];
    memset(dados, 0, sizeof(dados));

    dados[0] = 1;
    for(ulli i = 0; i < 11; i++) {
        for(ulli j = coins[i]; j <= MAX_DATA_SIZE; j++) {
            dados[j] += dados[j-coins[i]];
        }
    }
    int dols, cents;
    
    while(scanf("%d.%d", &dols, &cents) == 2) {
        int q = dols * 100 + cents;
        if(q == 0)
            break;
        ulli out = dados[q];
        double num = dols + (double)cents/100;
        printf("%6.2lf %16llu\n", num, out);
    }
    return 0;
}
