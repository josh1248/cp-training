#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int start = s[0];
    int flips = 0;
    int curr = start;
    for (int i = 1; i < n; i++) {
        if (s[i] != curr) {
            curr = s[i];
            flips++;
        }
    }
    cout << flips + (start == '0' ? 0 : 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; while (t--) solve();
}