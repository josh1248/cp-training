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

    int c, p; cin >> c >> p;
    vi v(c);
    rep(i, 0, c) cin >> v[i];
    if (p == 1) {
        int acc = c;
        rep(i, 0, c - 3) {
            if (v[i] == v[i + 1] && v[i + 1] == v[i + 2] && v[i + 2] == v[i + 3]) {
                acc++;
            }
        }
        cout << acc << "\n";
        return 0;
    } else if (p == 2) {
        int acc = 0;
        rep(i, 0, c - 1) {
            if (v[i] == v[i + 1]) acc++;
        }
        cout << acc << "\n";
        return 0;
    } else if (p == 5) {
        int acc = 0;
        rep(i, 0, c - 1) {
            if (abs(v[i] - v[i + 1]) == 1) acc++;
        }
        rep(i, 0, c - 2) {
            if (v[i] == v[i + 1] && v[i + 1] == v[i + 2]) acc++;
            else if (v[i] == v[i + 2] && v[i + 1] + 1 == v[i]) acc++;
        }
        cout << acc << "\n";
    }

    function<int(void)> solve3 = [&](){
        int acc = 0;
        rep(i, 0, c - 1) {
            if (v[i] == v[i + 1] + 1) acc++;
        }
        rep(i, 0, c - 2) {
            if (v[i] == v[i + 1] && v[i + 1] + 1 == v[i + 2]) acc++;
        }
        return acc;
    };

    if (p == 3) {
        cout << solve3() << "\n";
    } else if (p == 4) {
        reverse(all(v));
        cout << solve3() << "\n";
    }

    function<int(void)> solve6 = [&](){
        int acc = 0;
        rep(i, 0, c - 1) {
            if (v[i] == v[i + 1] + 2) acc++;
            else if (v[i] == v[i + 1]) acc++;
        }
        rep(i, 0, c - 2) {
            if (v[i] == v[i + 1] && v[i + 1] == v[i + 2]) acc++;
            else if (v[i + 1] == v[i + 2] && v[i] + 1 == v[i + 1]) acc++;
        }
        return acc;
    };

    if (p == 6) cout << solve6() << "\n";
    else if (p == 7) {
        reverse(all(v));
        cout << solve6() << "\n";
    }
}