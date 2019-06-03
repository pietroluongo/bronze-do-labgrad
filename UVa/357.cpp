// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=143&page=show_problem&problem=293
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define ulli unsigned long long int

#define MAX_DATA_SIZE 30100

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
        ulli out = dados[num];
        if(out == 1) {
            cout << "There is only 1 way to produce " << num << " cents change." << endl;
        }
        else {
            cout << "There are " << out << " ways to produce " << num << " cents change." << endl;
        }
    }
    return 0;
}
