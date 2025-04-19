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

    string prev; cin >> prev;
    char target = prev[sz(prev) - 1];
    int n; cin >> n;
    vector<string> names(n);
    rep(i, 0, n) cin >> names[i];
    vi startcnts(26);
    rep(i, 0, n) {
        startcnts[names[i][0] - 'a']++;
    }
    // 0: not possible, 1: play without eliminate, 2: play and eliminate
    int status = 0; string currbest = "?";
    rep(i, 0, n) {
        char startchar = names[i][0], endchar = names[i][sz(names[i]) - 1];
        if (startchar == target) {
            if (startcnts[endchar - 'a'] - (startchar == endchar ? 1 : 0) == 0) {
                status = 2;
                currbest = names[i];
                break;
            } else if (status == 0) {
                status = 1;
                currbest = names[i];
            }
        }
    }
    cout << currbest << (status == 2 ? "!" : "") << "\n";
}