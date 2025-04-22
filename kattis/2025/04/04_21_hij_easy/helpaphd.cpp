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

    int t; cin >> t;
    string s;
    rep(i, 0, t) {
        cin >> s;
        if (s.find('=') != string::npos) cout << "skipped\n";
        else {
            ll a = stoi(s.substr(0, s.find('+'))),
                b = stoi(s.substr(s.find('+') + 1));
            cout << a + b << "\n";
        }
    }
}