#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k; cin >> n >> k;
    set<int> notes;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; notes.insert(x);
    }
    int res = 0;
    int curr = int(-2e9);
    for (int n: notes) {
        if (ll(n) - curr > ll(k)) {
            res++;
            curr = n;
        }
    }
    cout << res << "\n";
}