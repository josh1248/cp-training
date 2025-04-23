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

    int n, p, x, y; cin >> n >> p >> x >> y;
    int completeblocks = p / (n - 1);
    int remainder = p % (n - 1);
    cout << completeblocks * (x * (n - 1) + y) + remainder * x << "\n";
}