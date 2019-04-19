//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=1023
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct proposal {
    string name;
    float price;
    int met_requirements;
    float compliance;
};

int main() {
    int requirement_count, proposal_count;
    int rfp_count = 0;
    while(scanf("%d %d\n", &requirement_count, &proposal_count) == 2) {
        rfp_count++;
        if(requirement_count == 0 && proposal_count == 0)
            break;
        vector<string> requirements;
        proposal proposals[proposal_count];
        for(int i = 0; i < requirement_count; i++) {
            string s;
            getline(cin, s);
            requirements.push_back(s);
        }
        for(int i = 0; i < proposal_count; i++) {
            cin >> proposals[i].name;
            proposals[i].met_requirements = 0;
            proposals[i].compliance = 0;
            int provided_requirements;
            scanf("%f %d\n", &proposals[i].price, &provided_requirements);
            for(int j = 0; j < provided_requirements; j++) {
                string current_requirement;
                getline(cin, current_requirement);
                if(find(requirements.begin(), requirements.end(), current_requirement) != requirements.end()) {
                    proposals[i].met_requirements++;
                }
            }
            proposals[i].compliance = (float)proposals[i].met_requirements / (float)requirement_count;


        }
        proposal best_proposal;
        best_proposal.compliance = 0;
        for(auto proposal : proposals) {
            if(proposal.compliance > best_proposal.compliance) {
                best_proposal = proposal;
                continue;
            }
            if(proposal.compliance == best_proposal.compliance) {
                if(proposal.price < best_proposal.price) {
                    best_proposal = proposal;
                    continue;
                }
            }
        }
        printf("RFP #%d\n", rfp_count);
        printf("Best proposal: %s\n", best_proposal.name.c_str());
        /*for(proposal p : proposals) {
            printf("%s %.2f %d\n", p.name.c_str(), p.price, p.met_requirements);
        }*/
    }
    return 0;
}
