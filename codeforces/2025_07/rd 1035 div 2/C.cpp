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

// for AND(ai) == XOR(ai), 2 options:
// for every bit:
// odd number of 1 bit, no 0 bits (1)
// even number of 1 bit, there is a 0 bit (0)
// if for a certain bit, l <= num <= r are all 1 bit, then it cannot equal if n is even
// otherwise, if seq length is odd:
// see if lowest number can do it
// if even:
// every bit needs to have 2/4/6/... numbers with 0, the rest 1
// optimize with MSD?
// -> parity of 1s == complement(presence of 0s)

// lets just do it for first bit
// if even length, check if ???
// fop 2nd bit????
int main() {
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