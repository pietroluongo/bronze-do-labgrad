// From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=3402
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, string> lmap;
    lmap["HELLO"] = "ENGLISH";
    lmap["HOLA"] = "SPANISH";
    lmap["HALLO"] = "GERMAN";
    lmap["BONJOUR"] = "FRENCH";
    lmap["CIAO"] = "ITALIAN";
    lmap["ZDRAVSTVUJTE"] = "RUSSIAN";
    char str[999];
    int i = 0;
    while(scanf("%s\n", str) == 1) {
        if(str[0] == '#')
            break;
        string input;
        input += str;
        if(lmap.find(input) == lmap.end()) {
            cout << "Case " << ++i << ": UNKNOWN" << endl;
            continue;
        }
        cout << "Case " << ++i << ": " << lmap[input] << endl;
    }

    return 0;
}