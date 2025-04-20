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
        ll n, m, a, b, d;
        cin >> n >> m >> a >> b >> d;
        ll timetotravel = b - a;
        if (timetotravel < 0) timetotravel += n;
        ll timeback = b + d + timetotravel;
        ll nightthreshold = (n - m);
        cout << (timeback % n <= nightthreshold ? "YES" : "NO") << "\n";
    }
}