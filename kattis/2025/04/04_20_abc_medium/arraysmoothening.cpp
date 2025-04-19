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

    int n, k; cin >> n >> k;
    unordered_map<ll, int> cnts;
    rep(i, 0, n) {
        ll x; cin >> x;
        if (cnts.count(x) == 0) cnts[x] = 0;
        cnts[x]++;
    }

    priority_queue<ll> pq;
    for (auto& [key, val]: cnts) pq.emplace(val); 
    rep(i, 0, k) {
        auto val = pq.top(); pq.pop();
        pq.emplace(val - 1);
    }
    cout << pq.top() << "\n";
}