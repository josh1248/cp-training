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

    int n, m; cin >> n >> m;
    string res(n, '?');
    rep(i, 0, m) {
        int idx; string s;
        cin >> idx >> s;
        --idx;
        rep(j, 0, sz(s)) {
            if (idx + j >= n || (res[idx + j] != '?' && res[idx + j] != s[j])) {
                cout << "Villa\n";
                return 0;
            } 
            res[idx + j] = s[j];
        }
    }
    cout << res << "\n";
}