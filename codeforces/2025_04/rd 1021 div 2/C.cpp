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
    int n; cin >> n;
    map<int, int> nums;
    rep(i, 0, n) {
        int x; cin >> x;
        if (nums.count(x) == 0) nums[x] = 0;
        nums[x]++; 
    }

    // locked -> outcome for that day is fixed to one option, or else 1 previous bet will be legit
    int locked = -1;
    bool conseclocks = false; // locks apply for next day as well if needed.
    for (auto [day, reps]: nums) {
        if (reps >= 4) {
            cout << "Yes\n";
            return;
        } else if (reps >= 2) {
            if (locked == day + 1 || locked == day + 2 || (locked == day && conseclocks)) {
                cout << "Yes\n";
                return;
            } else {
                locked = day + 1;
                conseclocks = true;
            }
        } else if (reps == 1) {
            if (locked == day + 1 || locked == day + 2 || (locked == day && conseclocks)) {
                locked = day + 2;
                conseclocks = false;
            }
        }
    }
    cout << "No\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}