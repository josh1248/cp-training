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
    int N, cnt = 0; cin >> N;
    rep(i, 0, N) {
        string s; cin >> s;
        rep(i, 0, sz(s)) {
            s[i] = tolower(s[i]);
        }
        if ((s.find("pink") != string::npos) || (s.find("rose") != string::npos)) {
            cnt++;
        }
    }

    if (cnt == 0) {
        cout << "I must watch Star Wars with my daughter\n";
    } else {
        cout << cnt << "\n";
    }
}