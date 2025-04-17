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
    vector<string> s(5);
    rep(i, 0, 5) cin >> s[i];
    vi ans;
    rep(i, 0, 5) {
        if (s[i].find("FBI") != string::npos) ans.push_back(i);
    }
    if (sz(ans) == 0) cout << "HE GOT AWAY!\n";
    else {
        for (int i: ans) cout << " " << i + 1;
    }
}