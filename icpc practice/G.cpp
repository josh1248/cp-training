#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        int s, e;
        scanf("%d %d", &s, &e);
        char sf[s+1], ef[e+1];
        scanf("%s\n%s", &sf, &ef);
        vector<int> sones, eones;
        int os = 0;
        for (int i = 0; i < s; ++i) {
            if (sf[i] == '0') {
                sones.push_back(os);
                os = 0;
            } else if (sf[i] == '1') ++os;
            else return 1;
        }
        sones.push_back(os);
        os = 0;
        for (int i = 0; i < e; ++i) {
            if (ef[i] == '0') {
                eones.push_back(os);
                os = 0;
            } else if (ef[i] == '1') ++os;
            else return 1;
        }
        eones.push_back(os);
        if (sones.back() < eones.back() || sones[0] < eones[0] || (eones.size() == 1 && sones.size() > 1)) {
            printf("no\n");
            continue;
        }
        int ep = 0;
        for (int sp = 0; sp < sones.size() && ep < eones.size(); ++sp) if(sones[sp] >= eones[ep]) ++ep;
        if (ep < eones.size()) printf("no\n");
        else printf("yes\n");
    }
}