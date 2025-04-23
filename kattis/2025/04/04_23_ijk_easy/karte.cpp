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

    vector<bool> p(13), k(13), h(13), t(13);
    int pc = 13, kc = 13, hc = 13, tc = 13;
    string s; cin >> s;
    rep(i, 0, sz(s) / 3) {
        char suit = s[3 * i];
        int num = stoi(s.substr(3 * i + 1, 2)) - 1;
        if (suit == 'P') {
            if (p[num]) {
                cout << "GRESKA\n";
                return 0;
            }
            p[num] = true;
            --pc;
        } if (suit == 'K') {
            if (k[num]) {
                cout << "GRESKA\n";
                return 0;
            }
            k[num] = true;
            --kc;
        }
        if (suit == 'H') {
            if (h[num]) {
                cout << "GRESKA\n";
                return 0;
            }
            h[num] = true;
            --hc;
        }
        if (suit == 'T') {
            if (t[num]) {
                cout << "GRESKA\n";
                return 0;
            }
            t[num] = true;
            --tc;
        }
    }
    cout << pc << " " << kc << " " << hc << " " << tc << "\n";
}