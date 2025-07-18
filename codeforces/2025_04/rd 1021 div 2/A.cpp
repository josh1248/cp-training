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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        string x; cin >> x;
        vi cnts(10, 0);
        for (char c: x) cnts[c - '0']++;
        rep(pos, 1, 11) {
            int want = 10 - pos;
            rep(i, want, 10) {
                if (cnts[i] > 0) {
                    cnts[i]--;
                    cout << i;
                    break;
                }
            } 
        }
        cout << "\n";
    }
}