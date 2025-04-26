#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

vector<bool> isprime(10001, false);

void sieve() {
    isprime[1] = false;
    isprime[2] = true;
    rep(i, 2, 10001) {
        if (!isprime[i]) continue;
        for (int f = 2 * i; f <= 10000; f += i) {
            isprime[f] = false;
        }
    }
}

vvi graph(10001);

void make_graph() {
    rep(i, 0, )
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vi cnts(256, 0);
    int record = 0;
    string s;
    rep(i, 0, 5) {
        cin >> s;
        cnts[s[0]]++;
        record = max(record, cnts[s[0]]);
    }
    cout << record << "\n";
}