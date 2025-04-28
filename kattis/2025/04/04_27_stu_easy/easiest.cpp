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

    int x;
    while (cin >> x) {
        if (x == 0) return 0;
        int target = 0;
        int curr = x;
        while (curr > 0) {
            target += curr % 10;
            curr /= 10;
        }
        int p = 11;
        while (true) {
            ll check = x * p;
            ll acc = 0;
            while (check > 0) {
                acc += check % 10;
                check /= 10;
            }
            if (acc == target) {
                cout << p << "\n";
                break;
            }
            p++;
        }
    }
}