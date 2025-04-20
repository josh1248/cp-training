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
    cout << 45 * n << " ml gin\n";
    cout << 30 * n << " ml fresh lemon juice\n";
    cout << 10 * n << " ml simple syrup\n";
    cout << n << " slice" << (n > 1 ? "s" : "") << " of lemon\n";
}