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

void solve() {
    int N; cin >> N;
    string s; cin >> s;
    if (N == 1) {
        cout << -1 << "\n";
        return;
    }
    int initL = 0, initI = 0, initT = 0;
    for (char c: s) {
        if (c == 'L') initL++;
        else if (c == 'I') initI++;
        else initT++;
    }

    // int ILgap = -1, ITgap = -1, LTgap = -1;
    // rep(i, 0, sz(s) - 1) {
    //     if ((s[i] == 'I' && s[i + 1] == 'L') || (s[i] == 'L' && s[i + 1] == 'I')) {
    //         ILgap = i;
    //     } else if ((s[i] == 'I' && s[i + 1] == 'T') || (s[i] == 'T' && s[i + 1] == 'I')) {
    //         ITgap = i;
    //     } else if ((s[i] == 'L' && s[i + 1] == 'T') || (s[i] == 'T' && s[i + 1] == 'L')) {
    //         LTgap = i;
    //     }
    // }

    // we only need to consider insertion of the least frequent character
    // at most 2n ops needed.
    int l = initL, i = initI, t = initT;
    vi ops;
    while (l != i || l != t || i != t) {
        bool inserted = false;
        // consider insertion between the 2 lowest freq characters.
        // lowest freq is L. find an IT or TI gap now.
        if (l <= i && l <= t) {
            bool inserted = false;
            rep(x, 0, sz(s) - 1) {
                if ((s[x] == 'I' && s[x + 1] == 'T') || (s[x + 1] == 'I' && s[x] == 'T')) {
                    ops.push_back(x);
                    s.insert(x + 1, string(1, 'L'));
                    l++;
                    inserted = true;
                    break;
                }
            }
            if (inserted) {
                continue;
            }
        }

        // etc
        if (i <= l && i <= t) {
            bool inserted = false;
            rep(x, 0, sz(s) - 1) {
                if ((s[x] == 'L' && s[x + 1] == 'T') || (s[x + 1] == 'L' && s[x] == 'T')) {
                    ops.push_back(x);
                    s.insert(x + 1, string(1, 'I'));
                    inserted = true;
                    i++;
                    break;
                }
            }
            if (inserted) {
                continue;
            }
        }
    
        if (t <= l && t <= i) {
            bool inserted = false;
            rep(x, 0, sz(s) - 1) {
                if (((s[x] == 'I') && (s[x + 1] == 'L')) || ((s[x + 1] == 'I') && (s[x] == 'L'))) {
                    ops.push_back(x);
                    s.insert(x + 1, string(1, 'T'));
                    t++;
                    inserted = true;
                    break;
                }
            }
            if (inserted) {
                continue;
            }
        }

        if (!(l > i && l > t)) {
            bool inserted = false;
            rep(x, 0, sz(s) - 1) {
                if ((s[x] == 'I' && s[x + 1] == 'T') || (s[x + 1] == 'I' && s[x] == 'T')) {
                    ops.push_back(x);
                    s.insert(x + 1, string(1, 'L'));
                    l++;
                    inserted = true;
                    break;
                }
            }
            if (inserted) {
                continue;
            }
        }

        if (!(i > l && i > t)) {
            bool inserted = false;
            rep(x, 0, sz(s) - 1) {
                if ((s[x] == 'L' && s[x + 1] == 'T') || (s[x + 1] == 'L' && s[x] == 'T')) {
                    ops.push_back(x);
                    s.insert(x + 1, string(1, 'I'));     
                    inserted = true;
                    i++;
                    break;
                }
            }
            if (inserted) {
                continue;
            }
        }

        if (!(t > l && t > i)) {
            bool inserted = false;
            rep(x, 0, sz(s) - 1) {
                if (((s[x] == 'I') && (s[x + 1] == 'L')) || ((s[x + 1] == 'I') && (s[x] == 'L'))) {
                    ops.push_back(x);
                    s.insert(x + 1, string(1, 'T'));
                    t++;
                    inserted = true;
                    break;
                }
            }
            if (inserted) {
                continue;
            }
        }

        if (!inserted) {
            cout << -1 << "\n";
            return;
        }
    }

    if (sz(s) % 3 != 0) {
        cout << "Something's off: " << s << "\n";
    }
    cout << sz(ops) << "\n";
    for (int i: ops) cout << i + 1 << "\n"; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}