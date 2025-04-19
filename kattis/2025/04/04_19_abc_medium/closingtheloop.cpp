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

    int t; cin >> t; rep(i, 0, t) {
        cout << "Case #" << i + 1 << ": ";
        int n; cin >> n;
        vi reds, blues;
        rep(i, 0, n) {
            string x; cin >> x;
            if (x[sz(x) - 1] == 'B') {
                x.pop_back();
                blues.push_back(stoi(x));
            } else {
                x.pop_back();
                reds.push_back(stoi(x));
            }
        }
        sort(all(reds), greater<int>());
        sort(all(blues), greater<int>());

        if (sz(reds) == 0 || sz(blues) == 0) {
            cout << 0 << "\n";
        } else if (sz(reds) >= sz(blues)) {
            ll total = -2 * sz(blues);
            for (int i: blues) total += i;
            for (int i = 0; i < sz(blues); i++) total += reds[i];
            cout << total << "\n";
        } else {
            ll total = -2 * sz(reds);
            for (int i: reds) total += i;
            for (int i = 0; i < sz(reds); i++) total += blues[i];
            cout << total << "\n";  
        }
    }
}