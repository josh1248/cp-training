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

const int MOD = 1e9 + 7;

// Windows:
// 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17
// 	-fsanitize=undefined,address -o A A.cpp'
// Mac: 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17 -o A A.cpp'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, T, A, B, C, t0;
    cin >> N >> T >> A >> B >> C >> t0;
    vi problems(N);
    ll now = t0;
    problems[0] = t0;
    rep(i, 1, N) {
        now = (A * now + B) % C + 1;
        problems[i] = now;
    }
    sort(all(problems));
    ll penalty = 0, solved = 0, currtime = 0;
    rep (i, 0, N) {
        if (currtime + problems[i] > T) {
            break;
        }
        currtime += problems[i];
        penalty += currtime;
        penalty %= MOD;
        solved++;
    }

    cout << solved << " " << penalty << "\n";
}