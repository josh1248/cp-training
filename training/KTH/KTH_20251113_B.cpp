#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

// Windows:
// 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17
// 	-fsanitize=undefined,address -o A A.cpp'
// Mac: 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17 -o A A.cpp'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll slen;
    while (cin >> slen) {
        if (slen == 0) break;
        string s; cin >> s;

        int best = 0;
        rep(overlap, 1, slen) {
            bool flag = true;
            rep(i, 0, overlap) {
                if (s[i] != s[i + slen - overlap]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                best = overlap;
            }
        }
        
        cout << s + s.substr(best) << "\n";
    }
}