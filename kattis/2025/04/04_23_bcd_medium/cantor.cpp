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

    string s;
    while (cin >> s) {
        if (s == "END") return 0;
        double f = stold(s);
        if (f == 0 || f == 1) {
            cout << "MEMBER\n";
            continue;
        }
        bool hit = false;
        rep(i, 0, 30) {
            f *= 3;
            int dec = int(f + 1e-9);
            if (dec == 1) {
                cout << "NON-MEMBER\n";
                hit = true;
                break;
            }
            f -= dec;
        }
        if (!hit) cout << "MEMBER\n";
    }
}