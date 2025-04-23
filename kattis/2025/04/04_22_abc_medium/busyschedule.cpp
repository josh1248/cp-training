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

    int t;
    while (cin >> t) {
        if (t == 0) return 0;
        vector<pair<int, string>> times;
        rep(i, 0, t) {
            string n, m; cin >> n >> m;
            int hr = stoi(n.substr(0, n.find(":")));
            int min = stoi(n.substr(n.find(":") + 1));
            int evening = (m == "a.m." ? 0 : 1);
            int key = min + 60 * (hr == 12 ? 0 : hr) + 1440 * evening;
            times.emplace_back(key, n + " " + m);
        }
        sort(all(times));
        for(auto [k, s]: times) cout << s << "\n";
        cout << "\n";
    }
}