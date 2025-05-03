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
    int a = 0, b = 0;
    for (char c: s) {
        if (c == 'T') a++;
        else b++;

        if (a - b >= 2 && a >= 11) {
            a = 0, b = 0;
        } else if (b - a >= 2 && b >= 11) {
            a = 0, b = 0;
        }
    }
    cout << a << "-" << b << "\n";
}