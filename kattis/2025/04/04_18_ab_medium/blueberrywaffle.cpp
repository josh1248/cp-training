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

    int a, b; cin >> a >> b;
    double angle = remainder(180.0 * b / a, 360.0);
    if (angle < 0) angle += 360.0;
    if (angle < 90 || angle > 270) cout << "up\n";
    else cout << "down\n";

}