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

    int r, g, b; cin >> r >> g >> b;
    if (r == 255 && g == 255 && b == 255) {
        cout << "hvitur";
    } else if (r == 0 && g == 0 && b == 0) {
        cout << "svartur";
    } else if (r > g && r > b) {
        cout << "raudur";
    } else if (g > r && g > b) {
        cout << "graenn";
    } else if (b > r && b > g) {
        cout << "blar";
    } else if (r == g && b < r) {
        cout << "gulur";
    } else if (r == b && g < r) {
        cout << "fjolubleikur";
    } else if (g == b && r < g) {
        cout << "blagraenn";
    } else if (r == g && r == b) {
        cout << "grar";
    } else {
        cout << "othekkt";
    }
}