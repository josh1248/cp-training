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

    int n; cin >> n;
    string flush; getline(cin, flush);
    unordered_map<string, bool> names;
    unordered_map<string, string> last_names;
    string s;
    rep(i, 0, n) {
        getline(cin, s);
        if (s.find(' ') != string::npos) {
            string firstname = s.substr(0, s.find(' '));
            string lastname = s.substr(s.find(' ') + 1);
            names[firstname] = true;
            last_names[firstname] = lastname;
        } else {
            names[s] = false;
        }
    }
    int q; cin >> q;
    rep(i, 0, q) {
        cin >> s;
        if (names.count(s) == 0) cout << "Neibb\n";
        else if (names[s] == false) cout << "Jebb\n";
        else {
            cout << "Neibb en " << s << " " << last_names[s] << " er heima\n"; 
        }
    }
}