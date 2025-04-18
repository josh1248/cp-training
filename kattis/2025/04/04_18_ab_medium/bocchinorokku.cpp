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
    vi original(n);
    rep(i, 0, n) cin >> original[i];
    vi sorted(original);
    sort(all(sorted));
    for (int i: original) {
        cout << distance(begin(sorted), lower_bound(all(sorted), i)) << " ";
    }
    cout << "\n";
}