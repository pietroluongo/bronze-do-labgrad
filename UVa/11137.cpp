// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=143&page=show_problem&problem=2078
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define ulli unsigned long long int

#define MAX_DATA_SIZE 10005

int main() {
    ulli cubes[22];

    for(ulli i = 1; i <= 21; i++) {
        cubes[i] = i*i*i;
    }

    ulli dados[MAX_DATA_SIZE];
    memset(dados, 0, sizeof(dados));

    dados[0] = 1;
    for(ulli i = 1; i <= 21; i++) {
        for(ulli j = cubes[i]; j < MAX_DATA_SIZE; j++) {
            dados[j] += dados[j-cubes[i]];
        }
    }

    int num;
    while(cin >> num) {
        cout << dados[num] << endl;
    }
    return 0;
}
