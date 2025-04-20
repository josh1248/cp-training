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

    string s; getline(cin, s);
    string percent; getline(cin, percent);
    ll threshold_percent = 100 * stoi(percent.substr(0, 1)) + stoi(percent.substr(2));
    ll non_plastic = 0;
    int q;
    getline(cin, s);
    q = stoi(s);
    string x;
    rep(i, 0, q) {
        getline(cin, x);
        if (x == "ekki plast") non_plastic++;
    }

    // non_plastic / q <= threshold / 100
    // non_plastic * 100 <= threshold * q
    if (threshold_percent == 0) {
        cout << (non_plastic > 0 ? "Neibb" : "Jebb") << "\n";
    } else if (threshold_percent == 100) {
        cout << "Jebb\n";
    } else if (non_plastic * 100 <= threshold_percent * q) cout << "Jebb\n";
    else cout << "Neibb\n";
}