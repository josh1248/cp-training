#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

typedef unsigned long long ull;
ull h(ull x) {
    if (x == 1) return 1;
    else if (x % 2 == 0) return x + h(x / 2);
    else return x + h(3 * x + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ull n; cin >> n;
    cout << h(n) << "\n";
}