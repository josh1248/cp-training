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

    int e, f, c; cin >> e >> f >> c;
    e += f;
    int acc = 0;
    while (e >= c) {
        acc += e / c;
        e = (e % c) + e / c;
    }
    cout << acc << "\n";
}