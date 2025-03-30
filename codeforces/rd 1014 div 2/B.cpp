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
    string s1, s2; cin >> s1 >> s2;
    int oddDiagCount = 0, evenDiagCount = 0;
    int oddDiagCapacity = (N + 1) / 2, evenDiagCapacity = N / 2;
    rep(i, 0, N) {
        if (s1[i] == '0') continue;
        else if (i % 2 == 0) evenDiagCount++;
        else oddDiagCount++;
    }
    rep(i, 0, N) {
        if (s2[i] == '0') continue;
        else if (i % 2 == 0) oddDiagCount++;
        else evenDiagCount++;
    }
    cout << ((oddDiagCount <= oddDiagCapacity && evenDiagCount <= evenDiagCapacity) ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}