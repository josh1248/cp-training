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
    int timer = 0;
    for (char c: s) {
        if (timer > 0) {
            --timer;
            continue;
        }
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            timer = 2;
        }
        cout << c;
    }
}