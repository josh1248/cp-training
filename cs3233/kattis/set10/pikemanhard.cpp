#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (ll i = (a); i < (b); i++)

const ll MOD = 1e9 + 7;

// Windows:
// 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17
// 	-fsanitize=undefined,address -o A A.cpp'
// Mac: 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17 -o A A.cpp'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, T, A, B, C, t0;
    cin >> N >> T >> A >> B >> C >> t0;
    B %= C;
    vector<ll> time_to_idx(C + 1, -1ll), idx_to_time(C + 1, 0ll);
    // cycle finding
    ll idx = 1ll;
    ll t_now = t0;
    time_to_idx[t0] = 0;
    idx_to_time[0] = t0;
    ll init_length = 0, cycle_length = 0;
    while (true) {
        t_now = (A * t_now + B) % C + 1ll;
        if (time_to_idx[t_now] != -1ll) {
            // cycle found
            init_length = time_to_idx[t_now];
            cycle_length = idx - init_length;
            break;
        } else {
            // continue on
            time_to_idx[t_now] = idx;
            idx_to_time[idx] = t_now;
            idx++;
        }
    }

    // cout << init_length << " " << cycle_length << "\n";

    vector<ll> time_to_cnt(C + 1, 0);
    ll remaining = N;
    // those within the initial acyclic length
    rep(i, 0, init_length) {
        if (remaining == 0) break;
        ll t = idx_to_time[i];
        time_to_cnt[t]++;
        remaining--;
    }

    if (remaining > 0) {
        // now, those inside the cycle
        rep(i, init_length, init_length + cycle_length) {
            ll t = idx_to_time[i];
            ll cycle_pos = i - init_length;
            time_to_cnt[t] += (remaining / cycle_length);
            if (cycle_pos < ((remaining + cycle_length) % cycle_length)) {
                time_to_cnt[t]++;
            }
            // remaining--;
        }
    }
    
    // loop through problems in time order
    ll time_now = 0, time_left = T, problems_solved = 0ll, penalty = 0ll;
    rep(i, 1, C + 1) {
        if (time_to_cnt[i] == 0ll) continue;
        if (time_left < i) break;
        // how many problems can we solve?
        ll to_solve = min(time_left / i, time_to_cnt[i]);

        penalty = (penalty + (time_now * to_solve) % MOD ) % MOD;
        // i = time, jk = repeats.
        // i + 2i + 3i + ... + ki = i * k * (k + 1) / 2, closed form formula
        ll one_to_k;
        if (to_solve % 2ll == 0ll) {
            one_to_k = (to_solve / 2ll * (to_solve + 1ll)) % MOD;
        } else {
            one_to_k = ((to_solve + 1ll) / 2ll * to_solve) % MOD;
        }
        penalty = (penalty + ((one_to_k % MOD) * i) % MOD) % MOD;
        //  cout << penalty << "\n";

        problems_solved += to_solve;
        time_now += to_solve * i;
        time_left -= to_solve * i;
        // cout << "Solve " << to_solve << " problems with time " << i << ", time used = " << time_now << ", penalty" << penalty << "\n";
    }
    cout << problems_solved << " " << penalty % MOD << "\n";
    return 0;
}