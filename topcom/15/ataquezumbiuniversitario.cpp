#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <limits.h>
using namespace std;

#define EMPTY 0
#define ZOMBIE 1
#define HUMAN 2

#define CAS_H ((2 * bomb_h) + 1)
#define CAS_W ((2 * bomb_w) + 1)

struct cell {
    int human_casualties;
    int zombie_casualties;
};

int main() {
    int univ_count;
    scanf("%d\n", &univ_count);
    for(int counter = 0; counter < univ_count; counter++) {
        int bomb_h, bomb_w;
        scanf("%d %d\n", &bomb_h, &bomb_w);
        int field_w, field_h;
        scanf("%d %d\n", &field_w, &field_h);
        int uni[field_h][field_w];
        for(int i = 0; i < field_h; i++) {
            for(int j = 0; j < field_w; j++) {
                char c;
                scanf("%c", &c);
                uni[i][j] = c - '0';
            }
            scanf("%*[\n]");
        }
        int cas_w = field_w - 2 * bomb_w;
        int cas_h = field_h - 2 * bomb_h;
        cell casualties[cas_h][cas_w];
        for(int i = 0; i < cas_h; i++) {
            for(int j = 0; j < cas_w; j++) {
                casualties[i][j].zombie_casualties = 0;
                casualties[i][j].human_casualties = 0;
                for(int m = i; m < i + ((2 * bomb_h) + 1); m++) {
                    for(int n = j; n < j + ((2 * bomb_w) + 1); n++) {
                        if(n < 0 || m < 0 || n >= field_w || m >= field_h)
                            printf("OUTTA BOUNDS BOY");
                        int k = uni[m][n];
                        if(k == EMPTY)
                            continue;
                        else if(k == ZOMBIE)
                            casualties[i][j].zombie_casualties++;
                        else if(k == HUMAN)
                            casualties[i][j].human_casualties++;
                    }
                }
            }
        }
        cell* ideal;
        cell base;
        base.human_casualties = INT_MAX;
        base.zombie_casualties = 0;
        ideal = &base;
        int ideal_x = 0, ideal_y = 0;
        // Priority order calculation
        for(int i = 0; i < cas_h; i++) {
            for(int j = 0; j < cas_w; j++) {
                if(casualties[i][j].zombie_casualties > ideal->zombie_casualties) {
                    ideal = &casualties[i][j];
                    ideal_y = i + bomb_h;
                    ideal_x = j + bomb_w;
                }
                else if(casualties[i][j].zombie_casualties == ideal->zombie_casualties) {
                    if(ideal->human_casualties > casualties[i][j].human_casualties) {
                        ideal = &casualties[i][j];
                        ideal_y = i + bomb_h;
                        ideal_x = j + bomb_w;
                    }
                }
            }
        }
        printf("X:%d Y:%d\n", ideal_x, ideal_y);

    }
    return 0;
}