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

    vector<string> cards(12);
    rep(i, 0, 12) cin >> cards[i];
    vi c(9, 0);
    c.resize(12, 1);
    vvi ans;
    do {
        set<char> d1,d2,d3,d4;
        rep(i, 0, 12) {
            if (c[11 - i] == 1) {
                d1.insert(cards[i][0]);
                d2.insert(cards[i][1]);
                d3.insert(cards[i][2]);
                d4.insert(cards[i][3]);
            }
        }

        if (sz(d1) % 2 == 1 && sz(d2) % 2 == 1 && sz(d3) % 2 == 1 && sz(d4) % 2 == 1) {
            ans.push_back(vi());
            rep(i, 0, 12) {
                if (c[11 - i] == 1) {
                    ans.back().push_back(i + 1);
                }
            }
        }
    } while (next_permutation(all(c)));

    sort(all(ans));
    for (auto v: ans) {
        for (auto i: v) {
            cout << i << " ";
        }
        cout << "\n";
    }

    if (sz(ans) == 0) {
        cout << "no sets\n";
    }
}