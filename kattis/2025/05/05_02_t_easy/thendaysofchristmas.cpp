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

    vi prefs(367, 0);
    prefs[0] = 0, prefs[1] = 1;
    rep(i, 2, 367) {
        prefs[i] = prefs[i - 1] + i;
    }
    vi accs(367, 0);
    int a = 0;
    rep(i, 0, 367) {
        a += prefs[i];
        accs[i] = a;
    }

    int x; cin >> x;
    cout << prefs[x] << "\n" << accs[x] << "\n";
}