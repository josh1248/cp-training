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

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    
    int dx12 = x2 - x1, dx13 = x3 - x1, dx23 = x3 - x2;
    int dy12 = y2 - y1, dy13 = y3 - y1, dy23 = y3 - y2;

    // x1 y1 is diagonal to missing point
    if (dx12*dx12 + dy12*dy12 == dx13*dx13 + dy13*dy13) {
        // cout << "CASE1 ";
        // vector addition
        cout << x1 + dx12 + dx13 << " " << y1 + dy12 + dy13 << "\n";
    } else if (dx12*dx12 + dy12*dy12 == dx23*dx23 + dy23*dy23) {
        // cout << "CASE2 ";
        cout << x2 - dx12 + dx23 << " " << y2 - dy12 + dy23 << "\n";
    } else {
        // cout << "CASE3 ";
        cout << x3 - dx13 - dx23 << " " << y3 - dy13 - dy23 << "\n";
    }
}