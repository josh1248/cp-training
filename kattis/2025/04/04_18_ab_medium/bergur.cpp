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
    vi days(n); rep(i, 0, n) cin >> days[i];
    ll total = 0;
    int minseen = 9999999;
    for (int i = n - 1; i >= 0; i--) {
        minseen = min(minseen, days[i]);
        total += minseen;
    }
    cout << total << "\n";
}