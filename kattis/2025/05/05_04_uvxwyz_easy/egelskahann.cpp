#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int f(int i) {
    if (i <= 2) {
        return 1;
    } else if (i % 2 == 0) {
        return 2 * f(i / 2) - 1;
    } else {
        return 2 * f(i / 2) + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x; cin >> x;
    cout << f(x) << "\n";
}