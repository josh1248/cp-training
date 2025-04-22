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

    int t; cin >> t;
    cout << setprecision(9) << fixed;
    while (t--) {
        int b; double p;
        cin >> b >> p;
        cout << 60.0 * (b - 1) / p << " " << 60.0 * b / p << " " << 60.0 * (b + 1) / p << "\n";
    }
}