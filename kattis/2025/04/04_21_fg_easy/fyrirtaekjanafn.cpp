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

    string s; cin >> s;
    for (char c: s) {
        char d = tolower(c);
        if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u' || d == 'y') cout << c;
    }
    cout << "\n";
}