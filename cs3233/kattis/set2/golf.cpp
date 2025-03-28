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

    unordered_map<string, ll> hold;
    ordered_multiset scores;
    ll n, q; cin >> n >> q;
    for (ll i = 0; i < n; i++) {
        string s; cin >> s;
        hold[s] = 0;
        scores.insert({0LL, i});
    }

    ll max_idx = n;
    for (ll i = 0; i < q; i++) {
        char c; cin >> c;
        if (c == '?') {
            string s; cin >> s;
            cout << 1LL + scores.order_of_key({hold[s], -1L}) << " " << hold[s] << "\n";
        } else {
            ll x; cin >> x;
            for (ll j = 0; j < x; j++) {
                ll par_score; string player; cin >> player >> par_score;
                ll score = hold[player];
                scores.erase(scores.lower_bound({score, -1LL}));
                scores.insert({score + par_score, max_idx});
                hold[player] = score + par_score;
                max_idx++;
            }
        }
    }
}