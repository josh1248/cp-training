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
    bool hit = false;
    vi v(n);
    rep(i, 0, n) cin >> v[i];
    rep(f, 2, n + 1) {
        if (n % f != 0) continue;
        vi sectionmin(f, 1e9);
        vi sectionmax(f, -1e9);
        rep(i, 0, f) {
            rep(j, 0, n / f) {
                sectionmin[i] = min(sectionmin[i], v[i * (n / f) + j]);
                sectionmax[i] = max(sectionmax[i], v[i * (n / f) + j]);
            }
        }
        vi prefixmax(f, -1e9);
        int curr = -1e9;
        rep(i, 0, f) {
            curr = max(curr, sectionmax[i]);
            prefixmax[i] = curr;
        }
        bool issorted = true;
        rep(i, 1, f) {
            if (sectionmin[i] < prefixmax[i - 1]) {
                issorted = false;
                break;
            }
        }

        // cout << f << ": \n";
        // for (int i: prefixmax) cout << i << " ";
        // cout << "\n";
        // for (int i: sectionmin) cout << i << " ";
        // cout << "\n";

        if (issorted) {
            hit = true;
            cout << f << "\n";
        }
    }
    if (!hit) cout << -1 << "\n";
}