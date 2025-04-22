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

    int n; cin >> n;
    int base = 0;
    vi v(n);
    rep(i, 0, n) {
        int x; cin >> x;
        if (x == 1) {
            base++;
            v[i] = -1;
        }
        else {
            v[i] = 1;
        }
    }

    // our goal is to find the maximum subarray sum
    // subarray sum indicates how many extra bits we flip to 1.
    // use Kadane's algorithm
    int best = 0, curr = 0;
    for (int i: v) {
        curr = max(curr + i, 0);
        best = max(best, curr);
    }
    if (base == n) {
        cout << n - 1 << "\n";
    } else {
        cout << base + best << "\n";
    }
}