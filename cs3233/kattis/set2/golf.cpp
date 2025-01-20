#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<pi, null_type, less<pi> , rb_tree_tag ,
tree_order_statistics_node_update> ordered_multiset;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // -> first: index, -> second: par
    unordered_map<string, pi> hold;
    ordered_multiset scores;
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        hold[s] = {i, 0};
        scores.insert({0, i});
    }

    for (int i = 0; i < q; i++) {
        char c; cin >> c;
        if (c == '?') {
            string s; cin >> s;
            auto [idx, score] = hold[s];
            cout << 1 + scores.order_of_key({score, -10000}) << " " << score << "\n";
        } else {
            int x; cin >> x;
            for (int j = 0; j < x; j++) {
                int par_score; string player; cin >> player >> par_score;
                auto [idx, score] = hold[player];
                scores.erase({score, idx});
                score += par_score;
                scores.insert({score, idx});
                hold[player] = {idx, score};
            }
        }
    }
}