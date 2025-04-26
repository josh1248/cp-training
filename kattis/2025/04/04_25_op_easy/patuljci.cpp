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

    vi choices(9);
    vi c(2, 0);
    c.resize(9, 1);
    rep(i, 0, 9) cin >> choices[i];
    do {
        int acc = 0;
        rep(i, 0, 9) {
            acc += c[i] * choices[i];
        }
        if (acc == 100) {
            rep(i, 0, 9) {
                if (c[i] == 1) {
                    cout << choices[i] << "\n";
                }
            }
        }
    } while (next_permutation(all(c)));
}