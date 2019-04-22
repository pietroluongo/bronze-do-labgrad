#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
    int test_cases;
    scanf("%d", &test_cases);
    getchar();
    getchar();
    for(int i = 0; i < test_cases; i++) {
        map<string, int> species;
        species.clear();
        int total = 0;
        while(1) {
            string s;
            getline(cin, s);
            if(s == "")
                break;
            species[s]++;
            total++;
        }
        int counter = 0;
        for(auto it = species.begin();it != species.end(); it++) {
            counter++;
            printf("%s %.4f\n", it->first.c_str(), (100 * ((double) it->second)) / (double) total);
        }
        if(i != test_cases - 1)
            printf("\n");
    }

    return 0;
}