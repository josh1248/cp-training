#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).begin()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        bool flag = false;
        for (int i = sz(s) - 1; i >= 1; i--) {
            if (s[i] == s[i - 1]) {
                cout << 1 << "\n";
                flag = true;
                break;
            }
        }

        if (!flag) {
            cout << s.size() << "\n";
        }
    }
}