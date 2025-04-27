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

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) return 0;
        int a = -1, b = -1;
        rep(i, 0, n) {
            int x, y; cin >> x >> y;
            if (x > m) continue;
            if (a == -1 && b == -1) {
                a = x, b = y;
                continue;
            }

            if (a * y < b * x) {
                a = x, b = y;
            } else if (a * y == b * x) {
                if (x > a) {
                    a = x, b = y;
                }
            }
        }

        if (a == -1 && b == -1) {
            cout << "No suitable tickets offered\n";
        } else {
            cout << "Buy " << a << " tickets for $" << b << "\n";
        }
    }
}