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
    while (t--) {
        int n, m; cin >> n >> m;
        vvi prizes(n);
        vi rewards(n);
        rep(i, 0, n) {
            int req; cin >> req;
            vi reqs(req);
            rep(j, 0, req) cin >> reqs[j];
            cin >> rewards[i];
            prizes[i] = reqs;
        }
        vi cnts(m);
        rep(i, 0, m) cin >> cnts[i];
        ll acc = 0;
        rep(i, 0, n) {
            int lowest = 1e8;
            for (int r: prizes[i]) {
                lowest = min(lowest, cnts[r - 1]);
            }
            acc += lowest * rewards[i];
        }
        cout << acc << "\n";
    }
}