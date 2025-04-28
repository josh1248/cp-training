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

    char c; cin >> c;
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        cout << "Jebb\n";
    } else if (c == 'Y') {
        cout << "Kannski\n";
    } else {
        cout << "Neibb\n";
    }
}