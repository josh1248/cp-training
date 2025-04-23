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

    vi hitchance = {0,0,1,2,3,4,5,6,5,4,3,2,1};
    int n; cin >> n;
    int acc = 0;
    rep(i, 0, n) {
        int x; cin >> x;
        acc += hitchance[x];
    }
    cout << acc / 36.0 << "\n";
}