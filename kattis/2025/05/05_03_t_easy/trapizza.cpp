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

    int d, a, b, h;
    cin >> d >> a >> b >> h;
    double areaA = M_PI * d * d * 0.25;
    double areaB = (a + b) * h / 2.0;
    if (d == 0 && ((a == 0 && b == 0) || h == 0)) {
        cout << "Jafn storar!\n";
        return 0;
    }
    cout << (areaA < areaB ? "Trapizza!" : "Mahjong!") << "\n";
}