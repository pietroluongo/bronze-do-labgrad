// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=1644
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int countFreeSpaces(int* mat[], int w, int h) {
    int freeSpaces = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(mat[i][j] != 0) {
                freeSpaces++;
            }
        }
    }
    return freeSpaces;
}

int main() {
    int width, height, num;
    while(1) {
        scanf("%d %d %d\n", &width, &height, &num);
        if(width == 0 && height == 0 && num == 0)
            break;
        int matriz[width][height];
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                matriz[i][j] = 0;
            }
        }
        for(int i = 0; i < num; i++) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
            if(x1 > x2) {
                int buf = x1;
                x1 = x2;
                x2 = buf;
            }
            if(y1 > y2) {
                int buf = y1;
                y1 = y2;
                y2 = buf;
            }
            for(int j = y1; j <= y2; j++) {
                for(int k = x1; k <= x2; k++) {
                    matriz[j-1][k-1] ++;
                }
            }
        }
        int fspots = 0;
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                if(matriz[i][j] == 0) {
                    fspots++;
                }
            }
        }
        printf("%d\n", fspots);
        scanf("%*[\n]");
    }
    return 0;
}