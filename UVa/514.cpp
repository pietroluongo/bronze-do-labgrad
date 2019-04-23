#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

int main() {
    int n;
    bool flag = true;
    while(1) {
        scanf("%d", &n);
        if(n == 0) {

            break;
        }
//        else if (flag){
//            cout << endl;
//        }
//        flag = false;
        while(1) {
            stack<int> station;
            vector<int> train;
            for (int i = 1; i <= n; i++) {
                int aux;
                train.push_back(i);
            }
            vector<int> desired;
            bool aaaaaa = false;
            for (int i = 0; i < n; i++) {
                int aux;
                scanf("%d", &aux);
                if(aux == 0) {
                    aaaaaa = true;
                    break;
                }
                desired.push_back(aux);
            }
            if(aaaaaa)
                break;
            bool stopflag = false;
            for (int i = 0; i < n; i++) {
                if (station.size() > 0 && station.top() == desired[i]) {
                    station.pop();
                } else if (train.size() > 0 && desired[i] == *train.begin()) {
                    train.erase(train.begin());
                } else if (train.size() > 0) {
                    i--;
                    station.push(*train.begin());
                    train.erase(train.begin());
                } else {
                    printf("No\n");
                    stopflag = true;
                    break;
                }
            }
            if (stopflag)
                continue;
            else {
                printf("Yes\n");
            }
            
        }
        cout<< endl;
    }


}