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

    int h, k, v, s; cin >> h >> k >> v >> s;
    int acc = 0;
    while (h > 0) {
        v += s;
        v -= max(1, v / 10);
        if (v >= k) h++;
        if (v > 0 && v < k) {
            h--;
            if (h == 0) {
                v = 0;
            }
        }
        if (v <= 0) {
            h = v = 0;
        }
        acc += v;
        if (s > 0) s--;
    }
    cout << acc << "\n";
}