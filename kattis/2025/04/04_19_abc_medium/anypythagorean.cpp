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

    int circum; cin >> circum;
    if (circum < 12) {
        cout << "0 0 0\n";
        return 0;
    }
    for (int hypo = circum / 3; hypo < circum / 2 + 1; hypo++) {
        int alow = 1, ahigh = (circum - hypo) / 2;
        while (alow < ahigh) {
            int amid = (alow + ahigh + 1) / 2;
            int b = circum - hypo - amid;
            if (amid * amid + b * b < hypo * hypo) {
                ahigh = amid - 1;
            } else if (amid * amid + b * b > hypo * hypo) {
                alow = amid;
            } else {
                cout << amid << " " << b << " " << hypo << "\n";
                return 0;
            }
        }
        int b = circum - hypo - alow;
        if (alow * alow + b * b == hypo * hypo) {
            cout << alow << " " << b << " " << hypo << "\n";
            return 0;
        }
    }
    cout << "0 0 0 \n";
}