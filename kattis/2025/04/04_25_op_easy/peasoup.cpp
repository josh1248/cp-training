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

    string flush;
    int t; cin >> t;
    getline(cin, flush);
    while (t--) {
        int x; cin >> x;
        getline(cin, flush);
        string s; getline(cin, s);
        double pancake = false, peasoup = false;
        rep(i, 0, x) {
            string p; getline(cin, p);
            if (p == "pancakes") pancake = true;
            if (p == "pea soup") peasoup = true;
        }
        if (pancake && peasoup) {
            cout << s << "\n";
            return 0;
        }
    }
    cout << "Anywhere is fine I guess\n";
}