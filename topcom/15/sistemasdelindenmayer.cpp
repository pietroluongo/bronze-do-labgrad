#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct rule {
    string var;
    string replacement;
};

int main() {
    int gramatic_count;
    scanf("%d\n", &gramatic_count);
    for(int i = 0; i < gramatic_count; i++) {
        int order;
        scanf("%d\n", &order);
        // Axioma = base
        string axiom;
        getline(cin, axiom);
        int rule_count;
        scanf("%d\n", &rule_count);
        rule rules[rule_count];
        for(int j = 0; j < rule_count; j++) {
            char c;
            while(scanf("%c", &c) == 1) {
                if(c == '=')
                break;
                rules[j].var += c;
            }
            getline(cin, rules[j].replacement);
        }
        for(int j = 0; j < order; j++) {
            for(int k = 0; k < rule_count; k++) {
                rule r = rules[k];
                axiom.replace(axiom.find(r.var), r.var.length(), r.replacement);
            }
        }
        cout << axiom << endl;
    }
    return 0;
}