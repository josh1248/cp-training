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
    getline(cin, s);
    while (t--) {
        getline(cin, s);
        bool cap = true;
        for (char c: s) {
            cout << char(cap ? toupper(c) : tolower(c));
            cap = false;
        }
        cout << "\n";

    }
}