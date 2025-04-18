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

    int n; cin >> n;
    vector<tuple<double, double, string>> names;
    double lowest_time = 999999;
    vector<string> lowest_team;
    rep(i, 0, n) {
        string name; double x, y;
        cin >> name >> x >> y;
        names.emplace_back(-y, -x, name);
    }
    rep(i, 0, n) {
        vector<tuple<double, double, string>> v;
        rep(j, 0, n) {
            if (i == j) continue;
            v.emplace_back(names[j]);
        }
        double total_time = get<1>(names[i]);
        vector<string> curr_team;
        curr_team.push_back(get<2>(names[i]));
        make_heap(all(v));
        rep(j, 0, 3) {
            pop_heap(all(v));
            auto [a, b, name] = v[sz(v) - 1];
            v.pop_back();
            total_time += a;
            curr_team.push_back(name);
        }
        total_time = -total_time;
        if (total_time < lowest_time) {
            lowest_time = total_time;
            lowest_team = curr_team;
        }
    }
    cout << lowest_time << "\n";
    rep(i, 0, 4) cout << lowest_team[i] << "\n";
}