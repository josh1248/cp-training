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

    int cap, N; cin >> cap;
    vector<char> check = {'P', 'I', 'Z', 'A'};
    auto seed = chrono::system_clock::now().time_since_epoch().count();
    auto rng = default_random_engine(seed);
    string ans;
    bool flag = false;
    rep(i, 0, cap) {
        shuffle(all(check), rng);
        flag = false;
        rep(j, 0, 3) {
            ans.push_back(check[j]);
            cout << ans << endl;
            cin >> N;
            if (N == 1) {
                flag = true; break;
            } else if (N == 2) {
                return 0;
            } else {
                ans.pop_back();
            }
        }
        if (!flag) ans.push_back(check[3]);
    }
    if (!flag) cout << ans << endl;
    cin >> N;
    return 0;
}