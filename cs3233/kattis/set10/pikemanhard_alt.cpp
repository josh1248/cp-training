#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (ll i = a; i < (b); i++)

const int MOD = 1e9 + 7;

// Windows:
// 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17
//  -fsanitize=undefined,address -o A A.cpp'
// Mac: 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17 -o A A.cpp'

int repeats_in(int idx, int init_length, int cycle_length, int limit) {
    if (idx < init_length) {
        return 1ll;
    } else {
        int cycle_pos = idx - init_length;
        int total = limit - init_length;
        return total / cycle_length + ((total % cycle_length) > cycle_pos ? 1ll : 0ll);
    }
}

ll added_penalty_mod(ll init_time, ll time_per_problem, ll repeats_to_solve) {
    ll base_time = ((init_time % MOD) * repeats_to_solve) % MOD;
    // i = time, jk = repeats.
    // i + 2i + 3i + ... + ki = i * k * (k + 1) / 2, closed form formula
    ll one_to_k;
    if (repeats_to_solve % 2 == 0) {
        one_to_k = ((repeats_to_solve / 2ll) * (repeats_to_solve + 1ll)) % MOD;
    } else {
        one_to_k = (((repeats_to_solve + 1ll) / 2ll) * repeats_to_solve) % MOD;
    }
    return (base_time + (one_to_k * time_per_problem) % MOD) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, T, A, B, C, t0;
    cin >> N >> T >> A >> B >> C >> t0;
    vi idx_to_time;
    unordered_map<int, int> time_to_idx;
    // cycle finding
    int idx = 1ll;
    ll t_now = t0;
    idx_to_time.push_back(t0);
    time_to_idx[t0] = 0;
    int init_length = -1ll, cycle_length = -1ll;
    while (idx < N) {
        t_now = (A * t_now + B) % C + 1ll;
        if (time_to_idx.count(t_now) > 0) {
            // cycle found
            init_length = time_to_idx[t_now];
            cycle_length = idx - init_length;
            break;
        } else {
            // continue on
            idx_to_time.push_back(t_now);
            time_to_idx[t_now] = idx;
            idx++;
        }
    }

    // counting sort
    unordered_map<int, int> time_to_cnt;
    rep(i, 1, C + 1) {
        if (time_to_idx.count(i) == 0) continue;

        // no cycles.
        if (init_length == -1 && cycle_length == -1) {
            time_to_cnt[i] = 1;
            continue;     
        }

        time_to_cnt[i] = repeats_in(time_to_idx[i], init_length, cycle_length, N);
    }

    // loop through problems in time order
    ll time_now = 0, problems_solved = 0, penalty = 0;
    rep(i, 1, C + 1) {
        if (time_to_cnt.count(i) == 0) continue;
        else if ((T - time_now) < i ) break;
        // how many problems can we solve?
        ll to_solve = min((T - time_now) / i, ll(time_to_cnt[i]));
        penalty += added_penalty_mod(time_now, i, to_solve);
        penalty %= MOD;
        problems_solved += to_solve;
        time_now += to_solve * i;
    }
    cout << problems_solved << " " << penalty << "\n";
}