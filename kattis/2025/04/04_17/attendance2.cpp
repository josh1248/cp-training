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
    int n; cin >> n;
    vector<string> ins(n);
    rep(i, 0, n) cin >> ins[i];

    vector<string> absences;
    rep(i, 0, n) {
        if (ins[i] != "Present!" && (i == n - 1 || ins[i + 1] != "Present!")) absences.push_back(ins[i]);
    }

    if (sz(absences) == 0) cout << "No Absences\n";
    else {
        for (string s: absences) cout << s << "\n";
    }
}