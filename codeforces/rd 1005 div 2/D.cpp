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
    int n, q; cin >> n >> q;
    vi data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // store previous index with as many bits as number
    // O(n) with monotonic stack solution
    vector<pi> prevs;
    vector<pi> stack;
    stack.push_back({1000, -1});
    for (int i = 0; i < n; i++) {
        int msb_pos = 31 - __builtin_clz(data[i]);
        while (true) {
            auto [prev_msb, idx] = stack.back();
            if (prev_msb <= msb_pos) {
                stack.pop_back();
            }
            if (prev_msb >= msb_pos) {
                prevs.emplace_back(prev_msb, idx);
                break;
            }
            stack.pop_back();
        }
        stack.emplace_back(msb_pos, i);
    }
    reverse(all(stack)); // make it increasing
    vector init_mappings(31, 0);
    for (int i = 0; i < 31; i++) {
        auto& [msb, idx] = *lower_bound(all(stack), pi(i, -1));
        init_mappings[i] = idx;
    }
    


    // store prefix XORs
    // inclusion-exclusion trick works (XOR is commutative, and x^x == 0)
    vi prefixes;
    ll running_xor = 0;
    for (int i = 0; i < n; i++) {
        running_xor ^= data[i];
        prefixes.push_back(running_xor);
    }

    auto xor_range = [&](int i, int j) {
        if (i == 0) return prefixes[j];
        else return prefixes[j] ^ prefixes[i - 1];
    };

    for (int i = 0; i < 31; i++) {
        cout << i << ": " << init_mappings[i] << "\n";
    }
    
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        int curr_idx = n;
        while (true) {
            if (curr_idx == -1) {
                break;
            } else if (curr_idx == n) {
                int idx_to_consider = init_mappings[31 - __builtin_clz(x)];
            } else {
            }
        }
        cout << n - curr_idx - 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}