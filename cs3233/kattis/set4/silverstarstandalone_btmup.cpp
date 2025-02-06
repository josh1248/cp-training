#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

const int CAP = 211;
bool ok[CAP + 1];

void make_sieve() {
    memset(ok, 1, sizeof(ok));
    for (int i = 2; i <= CAP; i++) {
        if (ok[i]) {
            for (int j = 2 * i; j <= CAP; j += i) {
                ok[j] = false;
            }
        }
    }
}

// Windows:
// 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17
// 	-fsanitize=undefined,address -o A A.cpp'
// Mac: 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17 -o A A.cpp'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    make_sieve();
    
    int p; cin >> p;
    ll dp[p + 1];
    memset(dp, 0, sizeof(dp));
    dp[2] = 1;
    for (int i = 2; i <= p; i++) {
        if (!ok[i]) continue;
        for (int j = 1; j <= min(14, p - i); j++) {
            if (!ok[i+j]) continue;
            dp[i + j] += dp[i];
        }
    }
    cout << dp[p] << "\n";
}