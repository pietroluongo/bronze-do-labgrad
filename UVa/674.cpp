// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=615
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define ulli unsigned long long int

#define MAX_DATA_SIZE 7490

int main() {
    int coins[5] = {1, 5, 10, 25, 50};

    ulli dados[MAX_DATA_SIZE];
    memset(dados, 0, sizeof(dados));

    dados[0] = 1;
    for(ulli i = 0; i < 5; i++) {
        for(ulli j = coins[i]; j < MAX_DATA_SIZE; j++) {
            dados[j] += dados[j-coins[i]];
        }
    }

    int num;
    while(cin >> num) {
        cout << dados[num] << endl;
    }
    return 0;
}
