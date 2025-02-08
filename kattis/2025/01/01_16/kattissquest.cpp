#include <iostream>
#include <algorithm>
#include <cstdio>
#include <chrono>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, priority_queue<int>> rewards;
    int q; cin >> q;
    while (q--) {
        string s;
        int e, r;
        cin >> s;
        if (s == "add") {
            cin >> e >> r;
            if (rewards.count(e) == 0) {
                rewards.insert({e, priority_queue<int>()});
            }
            rewards[e].push(r);
        } else {
            cin >> e;
            ll res = 0;
            while (e > 0) {
                auto a = rewards.upper_bound(e);
                if (a == rewards.begin()) {
                    break;
                }
                a--;
                int used = a->first;
                int x = a->second.top();

                res += ll(x);
                a->second.pop();
                if (a->second.size() == 0) {
                    rewards.erase(used);
                }
                e -= used;
            }
            cout << res << "\n";
        }
    }
}