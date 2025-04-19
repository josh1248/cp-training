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

    cout << setprecision(2) << fixed;
    string s;
    ll currtime = 0, currspeed = 0;
    double acc_dist = 0;
    while (getline(cin, s)) {
        ll timestamp = 3600 * stoi(s.substr(0, 2)) 
            + 60 * stoi(s.substr(3, 2))
            + stoi(s.substr(6, 2));
        if (sz(s) > 8) {
            ll newspeed = stoi(s.substr(9));
            acc_dist += 1.0 * currspeed * (timestamp - currtime) / 3600;
            currtime = timestamp;
            currspeed = newspeed;
        } else {
            cout << s.substr(0, 8) << " " 
                << acc_dist + 1.0 * currspeed * (timestamp - currtime) / 3600 
                << " km\n";
        }
    }
}