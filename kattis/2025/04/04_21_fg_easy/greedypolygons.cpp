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
    cout << setprecision(9) << fixed;
    while (t--) {
        int n, l, d, g; cin >> n >> l >> d >> g;
        // https://en.wikipedia.org/wiki/Regular_polygon#Area
        double ngon = 0.25 * n * l * l / tan(M_PI / n);
        // combining curved portions form a circle
        double circle = M_PI * pow(d * g, 2);
        // rectangular region of expansion per side
        double side = n * l * d * g;
        cout << ngon + circle + side << "\n";
    }
}