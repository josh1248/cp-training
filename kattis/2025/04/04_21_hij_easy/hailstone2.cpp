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

    ll n; cin >> n;
    ll seqlength = 1;
    while (n > 1) {
        seqlength++;
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1; 
    }
    cout << seqlength << "\n";
}