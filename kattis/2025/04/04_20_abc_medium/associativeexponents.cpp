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

    int a, b, c; cin >> a >> b >> c;
    if (a == 1 || c == 1 || (b == 2 && c == 2)) cout << "What an excellent example!\n";
    else cout << "Oh look, a squirrel!\n";
}