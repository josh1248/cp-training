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
    string s; cin >> s;
    s.append(1, 'X');
    int best = 0; string now = "";
    for (char c: s) {
        if (c >= '0' && c <= '9') {
            now.append(1, c);
        } else if (sz(now) > 0) {
            int h = stoi(now);
            best = max(best, h);
            now = "";
        }
    }
    cout << best << "\n";
}