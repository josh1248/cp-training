#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; string s; cin >> n >> k >> s;
    vi prefix;
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') x++;
        prefix.push_back(x);
    }

    int res = 1e8;
    for (int i = 0; i < sz(prefix) - k - 1; i++) {
        if (s[i] == '#' && s[i + k + 1] == '#') {
            res = min(res, prefix[i + k + 1] - prefix[i] - 1);
        }
    }
    cout << (res == 1e8 ? "Neibb" : to_string(res)) << "\n";
}
