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




}