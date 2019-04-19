// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=746&page=show_problem&problem=2939
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>

#define THRESHOLD 127
#define MARKED <= THRESHOLD

using namespace std;

int main() {
    int question_count;
    while(scanf("%d", &question_count) == 1) {
        if(question_count == 0)
            break;
        scanf("%*[\n]");
        for(int i = 0; i < question_count; i++) {
            int marks[5];
            scanf("%d %d %d %d %d", &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]);
            int mark_count = 0;
            for(auto k : marks) {
                if(k MARKED) {
                    mark_count++;
                }
            }
            if(mark_count != 1)
                cout << "*" << endl;
            else {
                if(marks[0] MARKED)
                    cout << "A" << endl;
                else if(marks[1] MARKED)
                    cout << "B" << endl;
                else if(marks[2] MARKED)
                    cout << "C" << endl;
                else if(marks[3] MARKED)
                    cout << "D" << endl;
                else if(marks[4] MARKED)
                    cout << "E" << endl;
            }
        } 
    }
    return 0;
}