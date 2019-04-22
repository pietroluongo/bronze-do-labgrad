#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string s;
    while(1) {
        cin >> s;
        getchar();
        if(s == "#")
            break;
//        char st[100];
//        for(int i = 0; i < 100; i++) {
//            st[i] = '\0';
//        }
//        strcpy(st, s.c_str());
        if(next_permutation(s.begin(),s.end()))
        {
            cout << s << endl;
        }
        else {
            cout << "No Successor" << endl;
        }
    }
    return 0;
}