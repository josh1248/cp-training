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

    int n; string s; cin >> n >> s;
    int l = 0;
    int res = 0;
    for (char c: s) {
        if (c == '1') {
            res++;
            l = 2;
        } else if (l > 0) {
            res++;
            l--;
        }
    }
    cout << res << "\n";
}