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

    double r, x, y;
    cout << setprecision(9) << fixed;
    while (cin >> r) {
        cin >> x >> y;
        double squareddist = pow(x, 2) + pow(y, 2);
        if (squareddist > r * r) {
            cout << "miss\n";
            continue;
        }
        
        // find the chord length 
        double half_adj = pow(r * r - squareddist, 0.5);

        // calculate affected chord angle
        double chordangle = 2.0 * acos(pow(squareddist, 0.5) / r);

        // area == triangle + circle * unaffected chord angle
        double larger = half_adj * pow(squareddist, 0.5) + M_PI * r * r * (1 - chordangle / 2.0 / M_PI);
        double smaller = M_PI * r * r - larger;
        cout << larger << " " << smaller << "\n";
    }
}