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

    vi v(3);
    rep(i, 0, 3) cin >> v[i];
    sort(all(v));
    if (v[2] > 90) {
        cout << "Trubbig Triangel\n";
    } else if (v[2] < 90) {
        cout << "Spetsig Triangel\n";
    } else {
        cout << "Ratvinklig Triangel\n";
    }
}