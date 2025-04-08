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
    int N; cin >> N;
    vector<string> vs(N);
    rep(i, 0, N) cin >> vs[i];

    int a = 0;
    rep(l, 0, sz(vs[0])) {
        rep(r, l, sz(vs[0])) {
            bool ok = true;
            string check = vs[0].substr(l, r - l + 1);
            rep(i, 0, N) {
                if (int(vs[i].find(check)) == -1) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                a = max(a, r - l + 1);
            }
        }
    }
    cout << a << "\n";
}