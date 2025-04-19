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

void solve() {
    int N; cin >> N;
   
    vector<ll> nums(N), prefixmin(N), suffixgcd(N);
    rep(i, 0, N) cin >> nums[i];
    sort(all(nums));
    ll mintohit = nums[0];

    // minimum will always include smallest number
    ll gcdacc = -1;
    rep(i, 1, N) {
        // add into second half
        if (nums[i] % mintohit == 0) {
            if (gcdacc == -1) gcdacc = nums[i];
            else gcdacc = gcd(gcdacc, nums[i]);
        }
        // else, hide inside first half
    }
    cout << (gcdacc == mintohit ? "Yes" : "No") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}