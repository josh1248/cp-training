#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

vector<bool> isprime(10001, true);

vi primes;

void sieve() {
    isprime[1] = false;
    isprime[2] = true;
    rep(i, 2, 10001) {
        if (!isprime[i]) continue;
        for (int f = 2 * i; f <= 10000; f += i) {
            isprime[f] = false;
        }
    }
    rep(i, 1000, 10001) {
        if (isprime[i]) primes.push_back(i);
    }
}

vvi graph(10001);

void make_graph() {
    rep(i, 0, sz(primes)) {
        rep(j, i + 1, sz(primes)) {
            string a = to_string(primes[i]), b = to_string(primes[j]);
            int diffs = 0;
            rep(k, 0, 4) {
                if (a[k] != b[k]) diffs++;
            }
            // cout << primes[i] << " " << primes[j] << "\n";
            if (diffs == 1) {
                graph[primes[i]].emplace_back(primes[j]);
                graph[primes[j]].emplace_back(primes[i]);
            }
        }
    }
}

int SSSP(int u, int v) {
    queue<int> q;
    q.emplace(u);
    vi dists(10001, -1);
    dists[u] = 0;
    while (sz(q) > 0) {
        auto src = q.front(); q.pop();
        if (src == v) {
            return dists[v];
        }
        for (int& dest: graph[src]) {
            if (dists[dest] != -1) continue;
            q.emplace(dest);
            dists[dest] = dists[src] + 1;
        } 
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    make_graph();
    int t; cin >> t;
    while (t--) {
        int u, v; cin >> u >> v;
        int res = SSSP(u, v);
        if (res == -1) {
            cout << "Impossible\n";
        } else {
            cout << res << "\n";
        }
    }
}