#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

char getWinner(char m[3][3]) {
    char c;
    bool flag = false;
    for(int i = 0; i < 2; i++) {
        if(i == 1) {
            c = 'O';
        }
        if(i == 0) {
            c = 'X';
        }
        if(
            // Rows
            (m[0][0] == c && m[0][1] == c && m[0][2] == c) ||
           (m[1][0] == c && m[1][1] == c && m[1][2] == c) ||
           (m[2][0] == c && m[2][1] == c && m[2][2] == c) ||

            // Cols
           (m[0][0] == c && m[1][0] == c && m[2][0] == c) ||
           (m[0][1] == c && m[1][1] == c && m[2][1] == c) ||
           (m[0][2] == c && m[1][2] == c && m[2][2] == c) ||

           // Diags
           (m[0][0] == c && m[1][1] == c && m[2][2] == c) ||
           (m[0][2] == c && m[1][1] == c && m[2][0] == c)
           )
        {
            flag = true;
            break;

        }
    }
    if(flag)
        return c;
    return -1;
}

char getWinner2(char m[3][3]) {
    char c;
    bool flag = false;
    for(int i = 0; i < 2; i++) {
        if(i == 0) {
            c = 'O';
        }
        if(i == 1) {
            c = 'X';
        }
        if(
            // Rows
                (m[0][0] == c && m[0][1] == c && m[0][2] == c) ||
                (m[1][0] == c && m[1][1] == c && m[1][2] == c) ||
                (m[2][0] == c && m[2][1] == c && m[2][2] == c) ||

                // Cols
                (m[0][0] == c && m[1][0] == c && m[2][0] == c) ||
                (m[0][1] == c && m[1][1] == c && m[2][1] == c) ||
                (m[0][2] == c && m[1][2] == c && m[2][2] == c) ||

                // Diags
                (m[0][0] == c && m[1][1] == c && m[2][2] == c) ||
                (m[0][2] == c && m[1][1] == c && m[2][0] == c)
                )
        {
            flag = true;
            break;

        }
    }
    if(flag)
        return c;
    return -1;
}


int main(void){
    int n;
    scanf("%d\n", &n);
    char mat[3][3];
    for(int i = 0; i < n; i++) {
        int xs = 0, os = 0;
        for(int k = 0; k < 3; k ++) {
            for(int l = 0; l < 3; l++) {
                scanf("%c", &mat[k][l]);
                if(mat[k][l] == 'X')
                    xs++;
                else if(mat[k][l] == 'O')
                    os++;
            }
            scanf("%*[\n]");
        }
        if(os > xs)
        {
            printf("no\n");
            continue;
        }
        if(os > xs + 1 || xs > os + 1) {
            printf("no\n");
            continue;
        }
        if(getWinner(mat) == 'X' && os >= xs) {
            printf("no\n");
            continue;
        }
        if(getWinner(mat) == 'X' && getWinner2(mat) == 'O') {
            printf("no\n");
            continue;
        }
        if(getWinner(mat) == 'O' && os < xs) {
            printf("no\n");
            continue;
        }

        printf("yes\n");
    }
    return 0;
}