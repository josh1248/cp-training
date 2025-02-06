#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; string s; cin >> n >> k >> s;
    if (n - 2 < k) {
        cout << "Neibb\n"; return 0;
    }

    int x = 0;
    for (int i = 0; i < k + 1; i++) {
        if (s[i] == '#') x++;
    }

    int res = 1e8;
    for (int i = k + 1; i < sz(s); i++) {
        if (s[i] == '#') {
            if (s[i - k - 1] == '#') {
                res = min(res, x - 1);
            }
            x++;
        }

        if (s[i - k - 1] == '#') x--;
    }
    cout << (res == 1e8 ? "Neibb" : to_string(res)) << "\n";
}