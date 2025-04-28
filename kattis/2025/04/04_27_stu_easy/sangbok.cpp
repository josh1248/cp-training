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

    int limit, t; cin >> limit >> t;
    limit *= 60;
    int curr = 0;
    vi v(t);
    rep(i, 0, t) cin >> v[i];
    sort(all(v));
    rep(i, 0, t) {
        if (curr + v[i] > limit) {
            break;
        }
        curr += v[i];
    }
    cout << curr << "\n";
}