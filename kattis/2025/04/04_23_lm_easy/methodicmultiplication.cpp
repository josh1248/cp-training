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

    string a, b; cin >> a >> b;
    int ax = 0, bx = 0;
    for (char c: a) {
        if (c == 'S') ax++;
    }
    for (char c: b) {
        if (c == 'S') bx++;
    }
    int p = ax * bx;
    rep(i, 0, p) cout << "S(";
    cout << 0;
    rep(i, 0, p) cout << ")";
    cout << "\n";
}