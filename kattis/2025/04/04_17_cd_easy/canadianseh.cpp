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
    if (s[sz(s) - 3] != 'e' || s[sz(s) - 2] != 'h' || s[sz(s) - 1] != '?') {
        cout << "Imposter!\n";
    } else {
        cout << "Canadian!\n";
    }
}