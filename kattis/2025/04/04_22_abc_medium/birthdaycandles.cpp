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

    ll n, h, c; cin >> n >> h >> c;
    vector<vector<ll>> candles(n, vector<ll>(h));
    rep(i, 0, n) {
        rep(j, 0, h) {
            cin >> candles[i][j];
        }
    }
    rep(i, 0, n) {
        sort(all(candles[i]));
    }
    vector<ll> colsums(h);
    rep(i, 0, n) {
        rep(j, 0, h) {
            colsums[j] += candles[i][j];
        }
    }

    ll acc = 0;
    ll idx = -1;
    rep(i, 0, h) {
        if (colsums[i] + acc > c) break;
        idx = i;
        acc += colsums[i];
    }

    if (idx == h - 1) {
        cout << n * h << "\n";
        return 0;
    }

    vector<ll> toconsider;
    rep(i, 0, n) {
        toconsider.push_back(candles[i][idx + 1]);
    }
    sort(all(toconsider));
    rep(i, 0, n) {
        if (toconsider[i] + acc > c) {
            cout << n * (idx + 1) + i << "\n";
            break;
        }
        acc += toconsider[i];
    }

}