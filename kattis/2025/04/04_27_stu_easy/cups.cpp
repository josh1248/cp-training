#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    vector<pair<int, string>> res;

    rep(i, 0, t) {
        string a, b; cin >> a >> b;

        if (all_of(all(b), [](char c){ return c >= '0' && c <= '9'; })) {
            res.emplace_back(stoi(b), a);
        } else {
            res.emplace_back(stoi(a) / 2, b);
        }
    }
    sort(all(res));
    for (auto [k, v]: res) {
        cout << v << "\n";
    }
}