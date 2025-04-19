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

    int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;
    int g = 2 * (a1 + a2) + (b1 - a1) + (b2 - a2);
    int a3, b3, a4, b4; cin>> a3 >> b3 >> a4 >> b4;
    int e = 2 * (a3 + a4) + (b3 - a3) + (b4 - a4);
    if (g > e) cout << "Gunnar\n";
    else if (g < e) cout << "Emma\n";
    else cout << "Tie\n";
}