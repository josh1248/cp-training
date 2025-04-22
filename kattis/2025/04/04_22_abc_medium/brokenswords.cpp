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
    int tb = 0, lr = 0;
    string s;
    rep(i, 0, n) {
        cin >> s;
        if (s[0] == '0') tb++;
        if (s[1] == '0') tb++;
        if (s[2] == '0') lr++;
        if (s[3] == '0') lr++;
    }
    int used = min(tb / 2, lr / 2);
    cout << used << " " << tb - 2 * used << " " << lr - 2 * used << "\n";
}