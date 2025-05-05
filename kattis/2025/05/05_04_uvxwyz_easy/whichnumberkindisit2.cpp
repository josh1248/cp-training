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
        int x; cin >> x;
        bool o = x % 2;
        int sqrt = round(pow(x, 0.5));
        bool s = sqrt * sqrt == x;
        if (o && s) cout << "OS\n";
        else if (o) cout << "O\n";
        else if (s) cout << "S\n";
        else cout << "EMPTY\n";
    }
}