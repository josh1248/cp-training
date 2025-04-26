#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

const long long BASE_MOD = 998'244'353;
int binpow(int x, int n) {
    int ans = 1;
    while(n) {
        if(n & 1) ans = (long long) ans * x % BASE_MOD;
        n >>= 1;
        x = (long long) x * x % BASE_MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c; cin >> r >> c;
    cout << ll(binpow(r - 1, c - 1)) * ll(r) % BASE_MOD << "\n";
}