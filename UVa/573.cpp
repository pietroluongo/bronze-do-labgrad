//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=514
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int well_height, snail_climb, snail_slide, fatigue_factor;
    while(1) {
        scanf("%d %d %d %d", &well_height, &snail_climb, &snail_slide, &fatigue_factor);
        if (well_height == 0)
            break;
        int curHeight = 0;
        int curDay = 0;
        //Fatigue computing
        snail_climb *= 100;
        well_height *= 100;
        snail_slide *= 100;
        int fatigue = (snail_climb * fatigue_factor)/100;
        int hasFailed = 1;
        while (curHeight >= 0) {
            curDay++;
            // Climbs
            curHeight += snail_climb;
            if (curHeight > well_height) {
                hasFailed = 0;
                break;
            }
            // Fatigue
            snail_climb -= fatigue;
            if (snail_climb < 0)
                snail_climb = 0;
            // Slides
            curHeight -= snail_slide;
        }
        if (hasFailed)
            printf("failure on day %d\n", curDay);
        else
            printf("success on day %d\n", curDay);
    }
    return 0;
}
