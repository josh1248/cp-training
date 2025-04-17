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

    int n, ta, da, tb, db; cin >> n >> ta >> da >> tb >> db;

    int a = n * ta + da * n * (n - 1) / 2;
    int b = n * tb + db * n * (n - 1) / 2;
    cout << (a > b ? "Bob" : a < b ? "Alice" : "=") << "\n";
}