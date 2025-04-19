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

    int n; cin >> n;
    string flush; getline(cin, flush);
    vector<pair<string, string>> names;
    rep(i, 0, n) {
        string s; getline(cin, s);
        string key = "";
        rep(j, 0, sz(s)) {
            if (isupper(s[j])) {
                key = s.substr(j);
                break;
            }
        }
        names.emplace_back(key, s);
    }
    sort(all(names));
    for (auto& [k, v]: names) {
        cout << v << "\n";
    }
    return 0;
}