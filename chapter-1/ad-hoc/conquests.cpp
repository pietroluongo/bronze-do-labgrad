//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=1023
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int main() {
    map<string, int> dados;
    int lines;
    scanf("%d", &lines);
    for(int i = 0; i < lines; i++) {
        char country[75];
        string a;
        scanf("%s", country);
        getline(std::cin, a);
        // If map doesn't have key "country"
        if(!dados.count(country)) {
            dados.insert(pair<string, int>(country, 1));
        } else {
            dados[country]++;
        }
    }
    for(auto it = dados.cbegin(); it != dados.cend(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
