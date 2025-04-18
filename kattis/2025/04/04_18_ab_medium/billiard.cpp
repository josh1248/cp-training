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

    int a, b, s, m, n;
    while (cin >> a >> b >> s >> m >> n) {
        if (a == 0) {
            return 0;
        }
        ll dx = a * m, dy = b * n;
        double speed = pow(dx * dx + dy * dy, 0.5) / s;
        cout << setprecision(2) << fixed;
        cout << 180.0 / M_PI * atan(dy * 1.0 / dx) << " ";
        cout << speed << "\n";
    }
}