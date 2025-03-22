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

// https://github.com/stevenhalim/cpbook-code/blob/master/ch5/UVa00350.cpp 
// adapted for 1-in 1-out graphs.
vi graph;
vector<bool> hit;
int f(int x) {
    hit[x] = true;
    return graph[x];
}

pi floydCycleFinding(int x0) {                   // f(x) is defined above
    // 1st part: finding k*mu, hare h's speed is 2x tortoise t's
    int t = f(x0), h = f(f(x0));                   // f(x0) is after x0
    while (t != h) {
        if (t == -1 || h == -1) {
            return {-1, -1};
        }
        t = f(t);
        h = f(h);
        if (h == -1) {
            // not a cycle
            return {-1, -1};
        }
        h = f(h);
    }
    // 2nd part: finding mu, hare h and tortoise t move at the same speed
    int mu = 0; h = x0;
    while (t != h) { t = f(t); h = f(h); ++mu; }
    // 3rd part: finding lambda, hare h moves, tortoise t stays
    int lambda = 1; h = f(t);
    while (t != h) { h = f(h); ++lambda; }
    return {mu, lambda};
}

// Windows:
// 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17
// 	-fsanitize=undefined,address -o A A.cpp'
// Mac: 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17 -o A A.cpp'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        graph = vi(N + 1);
        hit = vector<bool>(N + 1, false);
        hit[0] = true;
        rep(i, 1, N + 1) {
            int x; cin >> x;
            graph[i] = x;
        }
        bool flag = true;
        rep(i, 0, N + 1) {
            if (!hit[i]) {
                auto [mu, lambda] = floydCycleFinding(i);
                // cout << i << " " << mu << " " << lambda << "\n";

                // if you build the graph:
                // it is a cycle
                // you start 1 after yourself in the cycle
                // you want to return to yourself in the cycle
                // you hop by distance 1 in 1st turn, by distance 2 in 2nd turn
                // total = 2^n - 1
                // the hope is that 2^n - 1 = (cycle - 1) mod cycle length
                // i.e. 2^n = 0 mod cycle
                // 2^n must be a multiple of cycle -> cycle is itself a power of 2!
                if (__builtin_popcount(lambda) != 1) {
                    cout << "Some starve.\n";
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << "All can eat.\n";
        }
    }

}