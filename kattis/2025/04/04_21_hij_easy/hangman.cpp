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

    string x, permutation; cin >> x >> permutation;
    int left = sz(x);
    int lives = 10;
    for (char c: permutation) {
        bool hit = false;
        for (char d: x) {
            if (c == d) {
                hit = true;
                left--;
            }
        }
        if (!hit) lives--;
        if (left == 0) break;
    }
    cout << (lives > 0 ? "WIN" : "LOSE") << "\n";
}