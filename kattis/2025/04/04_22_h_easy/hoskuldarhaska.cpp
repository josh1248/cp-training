#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

vector<vector<string>> vs;

void generate(string g, int idx) {
    if (idx >= sz(vs)) cout << g << "\n";
    else {
        for (string x: vs[idx]) {
            generate(g + x + " ", idx + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vs = vector<vector<string>>(n);
    rep(i, 0, n) {
        int k; cin >> k;
        string x;
        rep(j, 0, k) {
            cin >> x;
            vs[i].emplace_back(x);
        }
    }
    generate("", 0);
}