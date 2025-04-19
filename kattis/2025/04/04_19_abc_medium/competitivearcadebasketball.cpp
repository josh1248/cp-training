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
    int n, p, m; cin >> n >> p >> m;
    vi pts(n);
    unordered_map<string, int> mapping;
    rep(i, 0, n) {
        string name; cin >> name;
        mapping[name] = i;
    }
    bool success = false;
    rep(i, 0, m) {
        string name; int score; cin >> name >> score;
        if (pts[mapping[name]] >= p) continue;
        pts[mapping[name]] += score;
        if (pts[mapping[name]] >= p) {
            cout << name << " wins!\n";
            success = true;
        }
    }
    
    if (!success) cout << "No winner!\n";
}