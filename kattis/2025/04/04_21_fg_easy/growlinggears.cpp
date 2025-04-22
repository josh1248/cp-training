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
    while (t--) {
        int n; cin >> n;
        double recordgear = -1, recordtorque = -1e9;
        rep(i, 0, n) {
            int a, b, c; cin >> a >> b >> c;
            /*
                -aR^2 + bR + c
                = -a(R^2 - b/a R) + c
                = -a(R - (b / 2a)) ^2 + b^2/4a + c.
            */
            double highest = pow(b, 2) / 4.0 / a + c;
            if (highest > recordtorque) {
                recordtorque = highest;
                recordgear = i + 1;
            } 
        }
        cout << recordgear << "\n";
    }
}