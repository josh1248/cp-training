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
    const int A = 1, B = 2, AB = 3;

    string s1, s2; cin >> s1 >> s2;
    vvi dp(sz(s1), vi(sz(s2), -1));
    
    vvi parent(sz(s1), vi(sz(s2), -1));

    function<int(int, int)> dfs = [&](int s1ptr, int s2ptr) {
        if (s1ptr == sz(s1)) return sz(s2) - s2ptr;
        else if (s2ptr == sz(s2)) return sz(s1) - s1ptr;
        int& ans = dp[s1ptr][s2ptr];
        if (ans != - 1) return ans;

        int useBoth = 99999;
        if (s1[s1ptr] == s2[s2ptr]) {
            useBoth = 1 + dfs(s1ptr + 1, s2ptr + 1);
        }
        int useA = 1 + dfs(s1ptr + 1, s2ptr);
        int useB = 1 + dfs(s1ptr, s2ptr + 1);
        
        ans = min({useBoth, useA, useB});
        if (ans == useBoth) {
            parent[s1ptr][s2ptr] = AB;
        } else if (ans == useA) {
            parent[s1ptr][s2ptr] = A;
        } else {
            parent[s1ptr][s2ptr] = B;
        }
        return ans;
    };

    dfs(0, 0);
    string ans;
    int s1p = 0, s2p = 0;
    while (true) {
        if (s1p == sz(s1)) {
            ans.append(s2.substr(s2p));
            break;
        } else if (s2p == sz(s2)) {
            ans.append(s1.substr(s1p));
            break;
        } else if (parent[s1p][s2p] == AB) {
            ans.append(1, s1[s1p]);
            s1p++, s2p++;
        } else if (parent[s1p][s2p] == A) {
            ans.append(1, s1[s1p]);
            s1p++;
        } else {
            ans.append(1, s2[s2p]);
            s2p++;
        }
    }

    cout << ans << "\n";
}