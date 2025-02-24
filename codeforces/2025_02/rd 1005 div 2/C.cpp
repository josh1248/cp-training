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
    vll neg_suffixes(n + 1), pos_prefixes(n, 0), data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    ll running_sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (data[i] < 0) {
            running_sum -= data[i];
        }
        neg_suffixes[i] = running_sum;
    }
    running_sum = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] > 0) {
            running_sum += data[i];
        }
        pos_prefixes[i] = running_sum;
    }
    // all negative
    ll max_seen = neg_suffixes[0]; 
    for (int i = 0; i < n; i++) {
        max_seen = max(max_seen, pos_prefixes[i] + neg_suffixes[i + 1]);
    }
    cout << max_seen << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; while (t--) solve();
}