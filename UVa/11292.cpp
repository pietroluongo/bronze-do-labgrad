#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

#include <vector>

using namespace std;


int main() {
    int heads, knights;
    while (scanf("%d %d", &heads, &knights) == 2) {
        if(heads == 0 && knights == 0)
            break;
        vector<int> knightsData(knights);
        vector<int> headsData(heads);
        for(int i = 0; i < heads; i++) {
            scanf("%d", &headsData[i]);
        }

        for(int i = 0; i < knights; i++) {
            scanf("%d", &knightsData[i]);
        }

        sort(knightsData.begin(), knightsData.end());
        sort(headsData.begin(), headsData.end());

        int cost = 0;
        int cur_head = 0;
        int cur_knight = 0;
        bool isDoomed = false;
        while(cur_head < heads) {
            if(cur_knight == knights) {
                isDoomed = true;
                break;
            }
            if(knightsData[cur_knight] >= headsData[cur_head]) {
                cost += knightsData[cur_knight];
                cur_head++;
                cur_knight++;
            }
            else {
                cur_knight++;
            }
        }
        if(isDoomed) {
            printf("Loowater is doomed!\n");
        }
        else {
            printf("%d\n", cost);
        }
    }
    


    return 0;
}