//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=121&problem=2315
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
    int test_count;
    cin >> test_count;
    scanf("%*[\n]");
    for(int i = 0; i < test_count; i++) {
        map<char, int> values;
        int char_count;
        cin >> char_count;
        scanf("%*[\n]");
        // Fill values map
        for(int j = 0; j < char_count; j++) {
            char c;
            int p;
            scanf("%c %d\n", &c, &p);
            values[c] = p;
        }
        int line_count;
        cin >> line_count;
        scanf("%*[\n]");
        int cost = 0;
        for(int j = 0; j < line_count; j++) {
            string input;
            getline(cin, input);
            for(int k = 0; k < input.length(); k++) {
                // If key is present in map
                if(values.count(input[k]) > 0) {
                    cost += values[input[k]];
                }
            }
        }
        printf("%.2f$\n", (float)cost/100.0f);
    }
    return 0;
}