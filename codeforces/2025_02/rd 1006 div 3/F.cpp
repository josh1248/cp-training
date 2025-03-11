#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

// CLARIFY IF VECTOR COPYING IS PRESENT HERE - POST

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

vector<bool> solve(int n) {
    int msd = 31 - __builtin_clz(n);
    int msval = 1 << msd;
    if (n == msval) {
        // power of 2
        vector<bool> ans(msval, 1);
        return ans;
    } else {
        vector<bool> ans = solve(n - msval);
        // repeat prev solve, after padding with 0s up to 1 << msd
        ans.resize(n);
        rep(i, msval, n) {
            ans[i] = ans[i - msval];
        }
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<bool> res = solve(n);
        for (bool b: res) {
            cout << (b ? k : 0) << " ";
        }
        cout << "\n";
    }

    // vi prev = {1};
    // rep(i, 2, 10000) {
    //     vi now(i);
    //     now[0] = prev[0];
    //     now[i - 1] = prev[i - 2];
    //     rep(j, 1, i - 1) {
    //         now[j] = prev[j - 1] ^ prev[j];
    //     }
    //     prev = move(now);
    // }
}