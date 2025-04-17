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
    int N; string s;
    while (cin >> N) {
        if (N == 0) return 0;
        map<string, vector<string>> orders;
        getline(cin, s);
        rep(i, 0, N) {
            getline(cin, s);
            stringstream ss(s);
            vector<string> v;
            string x;
            while (ss >> x) v.push_back(x);
            rep(i, 1, sz(v)) {
                if (orders.count(v[i]) == 0) {
                    orders[v[i]] = {};
                }
                orders[v[i]].push_back(v[0]);
            }
        }

        for (auto& [k, v]: orders) {
            sort(all(v));
            cout << k;
            for (string& ans: v) cout << " " << ans;
            cout << "\n";
        }
        cout << "\n";
    }
}