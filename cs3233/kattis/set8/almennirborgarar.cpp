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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    ll grills[n];
    ll fastest = 1e10;
    rep(i, 0, n) {
        cin >> grills[i];
        fastest = min(fastest, grills[i]);
    }
    ll low = 0, high = fastest * (m + 1);
    while (low < high) {
        ll mid = (low + high) / 2;
        ll served = 0;
        for (ll& g: grills) {
            served += mid / g;
        }
        if (served >= m + 1) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << "\n";
}