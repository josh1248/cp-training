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

    vector<ll> sides(3);
    while (cin >> sides[0] >> sides[1] >> sides[2]) {
        if (sides[0] == 0) return 0;
        sort(all(sides));
        if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) {
            cout << "right\n";
        } else {
            cout << "wrong\n";
        }
    }
}