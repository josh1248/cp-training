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

    int n; cin >> n;
    bool running = false;
    int prev = 0;
    int acc = 0;
    rep(i, 0, n) {
        int x; cin >> x;
        if (!running) {
            running = true;
        } else if (running) {
            running = false;
            acc += (x - prev);
        }
        prev = x;
    }
    if (running) cout << "still running\n";
    else cout << acc << "\n";
}