#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).begin()

void solve() {
    int n; cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ll maxs = -1e9;
    for (int i = 0; i < n; i++) {
        // cout << "now: ";
        // for (int j = 0; j < n - i; j++) {
        //     cout << nums[j] << " ";
        // }

        ll sum = 0;
        for (int j = 0; j < n - i; j++) {
            sum += nums[j];
        }
        // cout << ": Sum " << sum << "\n";
        maxs = max(maxs, sum);

        // next sum is either a_n - a_1 or a_1 - a_n (flipped) - flip if necessary
        if (nums[n - i - 1] < nums[0]) {
            // cout << "flip\n";
            reverse(nums.begin(), nums.begin() + n - i);
        }

        for (int j = 0; j < n - i - 1; j++) {
            nums[j] = nums[j + 1] - nums[j];
        }

        // cout << "after: ";
        // for (int j = 0; j < n - i; j++) {
        //     cout << nums[j] << " ";
        // } cout << "\n";

    }
    cout << maxs << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}