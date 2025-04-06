#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

const long long BASE_MOD = 1'000'000'007;

ll binpow(int x, ll n) {
    int ans = 1;
    while(n) {
        if(n & 1) ans = (long long) ans * x % BASE_MOD;
        n >>= 1;
        x = (long long) x * x % BASE_MOD;
    }
    return ans;
}

void solve() {
    ll R, C, K; cin >> R >> C >> K;
    // parity of all internal cells + 4 corners have even no. of neighbours
    // their colour does not affect parity of total matches
    // (Proof: pairs if cell white + pairs if cell black = even, so both are either odd or both even)

    // 2nd realization: ceteris paribus, changing the color of a border cell changes the parity of the total matches
    // (Similar proof: pairs if cell white + pairs if cell black = odd, both must have differing parity)
    ll evens = (R - 2) * (C - 2) + 4;
    ll odds = 2 * (R + C) - 8;
    ll odd_blacks = 0;

    int r, c, color;
    rep(i, 0, K) {
        cin >> r >> c >> color;
        if (r > 1 && r < R && c > 1 && c < C) {
            // internal cells
            evens--;
        } else if ((r == 1 || r == R) ^ (c == 1 || c == C)) {
            // border cells, not corner
            odds--;
            if (color == 1) {
                odd_blacks++;
            }
        } else {
            // the 4 corner cells
            evens--;
        }
    }
    
    // if all cells were white, even parity
    // placing a black cell along the border changes parity
    // we need an even number of cells with odd no. of neighbours to be black
    // -> along free cells, we may need to pick an even or odd number of cells to be black
    // BUT this is not an issue:
    // nC0 + nC2 + nC4 + ... = nC1 + nC3 + nC5+...
    // proved elegantly using binomial expansion of (1 - 1)^n.
    // -> 2^(free cells - 1) choices to make (mult by internal cell choices) if >= 1 free cell.
    // If no free cells, 0 if odd no. of cells with odd neighbours are black, else just internal
    // cell choices.
    if (odds == 0) {
        if (odd_blacks % 2 == 0) {
            cout << binpow(2, evens) << "\n";
        } else {
            cout << 0 << "\n";
        }
    } else {      
        cout << binpow(2, (evens + odds - 1)) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}