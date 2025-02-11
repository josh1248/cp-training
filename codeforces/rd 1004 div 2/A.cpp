#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        if (y - x > 1) {
            cout << "No\n";
            continue;
        } else if (y - x == 1) {
            cout << "Yes\n";
        } else if ((x - y) % 9 == 8) {
            // reduce by 9n + 8 only
            cout << "Yes\n";            
        } else {
            cout << "No\n";
        }
       
    }
}