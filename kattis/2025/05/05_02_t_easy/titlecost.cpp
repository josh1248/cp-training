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

    string s, f; cin >> s >> f;
    double ffloat = stold(f);
    cin >> s >> f;
    if (sz(s) > int(floor(ffloat))) {
        cout << f << "\n";
    } else {
        cout << sz(s) << "\n";
    }
}