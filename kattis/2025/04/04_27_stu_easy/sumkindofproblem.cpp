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
        int n; cin >> n;
        cout << n << " ";
        int x; cin >> x;
        int s1 = (x * (x + 1)) / 2;
        int s3 = 2 * s1;
        int s2 = s3 - x;
        cout << s1 << " " << s2 << " " << s3 << "\n";
    }
}