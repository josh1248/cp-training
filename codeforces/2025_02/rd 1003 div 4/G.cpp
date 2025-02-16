#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    map<int, int> counts;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (counts.count(x) == 0) {
            counts[x] = 0;
        }
        counts[x]++;
    }

    int primes = 0;
    ll pairs = 0;
    for (auto& [val, cnt]: counts) {
        // if more than 2 primes
        if (more than  2 primes) {
            continue;
        }

        // if prime
        else if (prime) {
            // yourself
            pairs += cnt * (cnt - 1) / 2;
            // other primes
            pairs += cnt * primes;
            // for future use
            primes += cnt;
        }

        // 2 factors, square
        else if () {
            // yourself
            pairs += cnt * (cnt - 1) / 2;
            // non distinct factors
            pairs += cnt * f1;
        }

        // 2 factors, nonsquare
        else if () {
            // yourself
            pairs += cnt * (cnt - 1) / 2;
            // distinct factors
            pairs += cnt * f1;
            pairs += cnt * f2;
        }
    }

    cout << pairs << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}