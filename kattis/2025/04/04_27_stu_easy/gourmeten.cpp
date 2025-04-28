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

    int limit, courses; cin >> limit >> courses;
    vi v(courses);
    rep(i, 0, courses) cin >> v[i];
    vi DP(limit + 1);
    DP[0] = 1;
    rep(i, 1, limit + 1) {
        rep(j, 0, courses) {
            if (i >= v[j]) DP[i] += DP[i - v[j]];
        }
    }
    cout << DP[limit] << "\n";
}