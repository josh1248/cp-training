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

    const ll a = 1000000000, b = 0;
    int k; cin >> k;
    cout << 1 << "\n";
    cout << k << "\n";
    bool flag = true;
    for (int i = 0; i < k; i++) {
        if (flag) {
            cout << a << " " << a;
        } else {
            cout << b << " " << b;
        }
        flag = !flag;
        cout << "\n";
    }

    for (int i = 1; i <= k - 1; i++) {
        cout << i << " " << i + 1 << "\n";
    }
}