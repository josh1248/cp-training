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
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (n % 2 == 0 && k % 2 == 0) {
            cout << (n + k - 1) / k << "\n";
        } else if (n % 2 == 0 && k % 2 == 1) {
            cout << (n + k - 2) / (k - 1) << "\n";
        } else if (n % 2 == 1 && k % 2 == 1) {
            cout << 1 + ((n - k) + k - 2) / (k - 1) << "\n";
        } else {
            cout << 1 + ((n - k + 1) + k - 1) / (k) << "\n"; 
        }
    }
}