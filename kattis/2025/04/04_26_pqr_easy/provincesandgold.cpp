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

    int g, s, c; cin >> g >> s >> c;
    int acc = 3 * g + 2 * s + c;
    if (acc <= 1) {
        cout << "Copper\n";
    } else {
        string a = "", b = "";
        if (acc >= 8) a = "Province";
        else if (acc >= 5) a = "Duchy";
        else a = "Estate";

        if (acc >= 6) b = "Gold";
        else if (acc >= 3) b = "Silver";
        else b = "Copper";

        cout << a << " or " << b << "\n";
    }
}