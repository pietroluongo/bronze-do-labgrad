//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=208
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int flag = 0;
    char input;
    while(scanf("%c", &input) == 1) {
        if(input == '\"')
        {
            if(flag % 2 == 0)
                printf("``");
            else
                printf("\'\'");
            flag++;
            continue;
        }
        printf("%c", input);
    }
    return 0;
}

