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
    vector<string> status(n);
    rep(i, 0, n) cin >> status[i];
    bool prevdrunk = false;
    ll acc = 0;
    rep(i, 0, n) {
        if (prevdrunk && status[i] == "sober") acc++;
        if (status[i] == "sober") prevdrunk = false;
        else prevdrunk = true;
    }
    cout << acc << "\n";
}