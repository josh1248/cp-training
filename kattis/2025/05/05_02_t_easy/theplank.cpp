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

    vi ways(25, 0);
    ways[1] = 1, ways[2] = 2, ways[3] = 4;
    rep(i, 4, 25) {
        ways[i] = ways[i - 1] + ways[i - 2] + ways[i - 3];
    }
    int x; cin >> x;
    cout << ways[x] << "\n";
}