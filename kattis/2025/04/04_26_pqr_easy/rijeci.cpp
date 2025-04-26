#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

vector<ll> fibs(46);

void populate_fibs() {
    fibs[0] = 0, fibs[1] = 1;
    rep(i, 2, 46) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    populate_fibs();
    int n; cin >> n;
    cout << fibs[n - 1] << " " << fibs[n] << "\n";
}