#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

vector<vector<double>> AM;
vector<bool> visited;

void DFS(int idx, double r) {
    if (visited[idx]) return;
    visited[idx] = true;
    rep(i, 0, sz(AM[idx])) {
        if (visited[i]) continue;
        if (i == idx) continue;
        if (AM[idx][i] > r) continue;   
        DFS(i, r);
    }
}

void solve() {
    int s, V; cin >> s >> V;
    AM = vector<vector<double>>(V, vector<double>(V));
    vector<pi> coords(V);
    rep(i, 0, V) {
        cin >> coords[i].first >> coords[i].second;
    }
    rep(i, 0, V) {
        rep(j, 0, V) {
            int dx = coords[i].first - coords[j].first;
            int dy = coords[i].second - coords[j].second;
            AM[i][j] = pow(dx * dx + dy * dy, 0.5);
        }
    }
    double low = 0, high = 1e9;
    while (high - low >= 1e-5) {      
        double mid = (low + high) / 2;
        
        visited = vector<bool>(V, false);
        int connected_components = 0;
        rep(i, 0, V) {
            if (visited[i]) continue;
            connected_components++;
            DFS(i, mid);
        }

        if (connected_components > s) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << setprecision(2) << fixed;
    cout << high << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; while (t--) solve();
}