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

    int curr, t; cin >> curr >> t;
    rep(i, 0, t) {
        string s; int n; cin >> s >> n;
        cout << s << " ";
        cout << (curr > n ? "lokud" : "opin") << "\n";
    }
}