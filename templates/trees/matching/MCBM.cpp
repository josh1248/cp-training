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

vi match, vis;
vector<vi> AL;
int curr_iter = 0;

int Aug(int L) {
    if (vis[L]) return 0;
    vis[L] = 1;
    for (auto &R: AL[L]) {
        if ((match[R] == -1) || Aug(match[R])) {
            match[R] = L;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    match = vi(2 * N, -1), vis = vi(2 * N, -1), AL = vvi(2 * N);
    
    rep(i, 0, N) {
        int x; cin >> x;
        int v;
        rep(j, 0, x) {
            cin >> v; v--;
            // cout << i << " " << v + N << "\n";
            AL[i].push_back(v + N);
        }
    }

    int matches = 0;
    vi leftV(N, 0);
    for (int L = 0; L < N; ++L) {              // O(V+E)
        ++curr_iter;
        vi candidates;
        for (auto &R : AL[L])
          if (match[R] == -1)
            candidates.push_back(R);
        if ((int)candidates.size() > 0) {
          ++matches;
          leftV[L] = 1;                            // L is matched
          int a = rand()%(int)candidates.size();     // randomize this
          match[candidates[a]] = L;
        }
    }  
    
    rep(i, 0, N) {
        if (!leftV[i]) {
            ++curr_iter;
            matches += Aug(i);
        }
    }


    if (matches != N) {
        cout << "Neibb\n";
        return 0;
    }

    rep(i, 0, N) {
        cout << match[i + N] + 1 << " ";
    }
    cout << "\n";
    return 0;
}