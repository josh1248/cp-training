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
        char a, b, c, d; cin >> a >> b >> c >> d;
        int col1 = a - 'A', row1 = b - '1', col2 = c - 'A', row2 = d - '1';
        int diag1start = col1 + row1, diag1end = col2 + row2,
            diag2start = col1 - row1, diag2end = col2 - row2;
        
        if ((diag1start - diag1end + 100) % 2 != 0) {
            cout << "Impossible\n";
            continue;
        } else if (diag1start == diag1end && diag2start == diag2end) {
            cout << 0 << " " << a << " " << b << "\n";
        } else if (diag1start == diag1end || diag2start == diag2end) {
            cout << 1 << " " << a << " " << b << " " << c << " " << d << "\n";
        } else {
            cout << 2 << " " << a << " " << b << " ";
            // find some cell which sees both
            bool hit = false;
            rep(i, 0, 8) {
                if (hit) break;
                rep(j, 0, 8) {
                    int d1 = j + i, d2 = j - i;
                    if ((d1 == diag1start && d2 == diag2end) || (d2 == diag2start && d1 == diag1end)) {
                        cout << char(j + 'A') << " " << i + 1 << " " << char(c) << " " << d << "\n";
                        hit = true;
                        break;
                    }
                }
            }
        }
    }
}