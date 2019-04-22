#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
    int test_cases;
    scanf("%d\n", &test_cases);
    for(int i = 0; i < test_cases; i++) {
        int l;
        scanf("%d\n", &l);
        int dados[l];
        for(int j =0; j < l; j++) {
            scanf("%d", &dados[j]);
        }
        int swaps = 0;
        for(int m = 0; m < l; m++) {
            for(int n = m; n < l; n++) {
                if(dados[m] > dados[n]) {
                    int aux = dados[m];
                    dados[m] = dados[n];
                    dados[n] = aux;
                    swaps++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", swaps);
    }
    return 0;
}