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
    vi data(n, 0);
    rep(i, 0, n) {
        cin >> data[i];
    }
    int record = 0;
    int l = 0, r = 0;
    rep(i, 0, n) {
        int net = 0;
        rep(j, i + 1, n) {
            if (data[j] < data[i]) {
                net++;
                if (record < net) {
                    record = net;
                    l = i, r = j;
                }
            } else if (data[j] > data[i]) {
                net--;
            }
        }
    }

    cout << l + 1 << " " << r + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}