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

    string octal; cin >> octal;
    int dummies = (3 * sz(octal) % 4 == 0 ? 0 : 4 - (3 * sz(octal) % 4));
    string binary(sz(octal) * 3 + dummies, '0'); // to make this a multiple of 4
    rep(i, 0, sz(octal)) {
        int v = octal[i] - '0';
        if (v & (1 << 2)) binary[3 * i + dummies] = '1';
        if (v & (1 << 1)) binary[3 * i + dummies + 1] = '1';
        if (v & (1 << 0)) binary[3 * i + dummies + 2] = '1';
    }
    
    rep(i, 0, sz(binary) / 4) {
        int acc = 0;
        rep(j, 0, 4) {
            acc *= 2;
            acc += (binary[4 * i + j] - '0');
        }
        
        if (acc < 10) {
            cout << acc;
        } else {
            cout << (acc - 10 + 'a');
        }
    }
    cout << "\n";
}