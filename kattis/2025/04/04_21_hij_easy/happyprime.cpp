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

    int t; cin >> t;
    while (t--) {
        int n, num; cin >> n >> num;
        cout << n << " " << num << " ";
        if (num < 7) {
            cout << "NO\n";
            continue;
        }

        bool prime = true;
        rep(j, 2, int(round(pow(num, 0.5)) + 2)) {
            if (num % j == 0) {
                prime = false;
                break;
            }
        }
        if (!prime) {
            cout << "NO\n";
            continue;
        }

        ll acc = num;
        unordered_set<ll> m;
        bool happy = false;
        while (m.count(acc) == 0) {
            m.insert(acc);
            string s = to_string(acc);
            ll nxt = 0;
            for (char c: s) {
                nxt += (c - '0') * (c - '0');
            }
            if (nxt == 1) {
                happy = true;
                break;
            }
            acc = nxt;
        }
        cout << (happy ? "YES" : "NO") << "\n";
    }
}