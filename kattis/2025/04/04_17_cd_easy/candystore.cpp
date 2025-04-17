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

    int N, M; cin >> N >> M;
    vector<string> hit(26 * 26);
    vector<int> cnt(26 * 26);
    rep(i, 0, N) {
        string x, y; cin >> x >> y;
        int key = (x[0] - 'A') * 26 + (y[0] - 'A');
        hit[key] = x + " " + y;
        cnt[key]++;
    }
    rep(i, 0, M) {
        string x; cin >> x;
        int key = (x[0] - 'A') * 26 + (x[1] - 'A');
        if (cnt[key] > 1) cout << "ambiguous";
        else if (cnt[key] == 1) cout << hit[key];
        else cout << "nobody";
        cout << "\n";
    }
}