#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>> , rb_tree_tag ,
tree_order_statistics_node_update> ordered_multiset;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, pair<ll, ll>> hold;
    ordered_multiset scores;
    ll n, q; cin >> n >> q;
    for (ll i = 0; i < n; i++) {
        string s; cin >> s;
        hold[s] = {0, i};
        scores.insert({0, i});
    }

    for (ll i = 0; i < q; i++) {
        char c; cin >> c;
        if (c == '?') {
            string s; cin >> s;
            cout << 1LL + scores.order_of_key({hold[s].first, -1}) << " " << hold[s].first << "\n";
        } else {
            ll x; cin >> x;
            for (ll j = 0; j < x; j++) {
                ll par_score; string player; cin >> player >> par_score;
                auto [score, idx] = hold[player];
                scores.erase({score, idx});
                scores.insert({score + par_score, idx});
                hold[player] = {score + par_score, idx};
            }
        }
    }
}