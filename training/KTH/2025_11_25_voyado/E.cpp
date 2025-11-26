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
    int a, b; cin >> a >> b;
    multiset<int> trash;
    int x;
    rep(i, 0, a) {
        cin >> x;
        trash.insert(x);
    }

    int ans = 0;
    while (trash.size() > 0) {
        ans++;
        if (trash.size() == 1) {
            break;
        } else {
            int big = *--trash.end();
            trash.erase(--trash.end());
            int max_target = b - big;
            auto found = trash.upper_bound(max_target);
            
            if (found != trash.begin()) {
                trash.erase(--found);
            }
        }
    }
    cout << ans << "\n";
}