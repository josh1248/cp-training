#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

void solve() {
    string num, source, target;
    cin >> num >> source >> target;
    map<char, int> mappings;
    for (int i = 0; i < sz(source); i++) {
        mappings[source[i]] = i;
    }

    int base10num = 0;
    for (char c: num) {
        base10num *= sz(source);
        base10num += mappings[c];
    }

    string res = "";
    map<int, char> target_map;
    for (int i = 0; i < sz(target); i++) {
        target_map[i] = target[i];
    }
    while (base10num) {
        res += target_map[base10num % sz(target)];
        base10num /= sz(target);
    }
    reverse(all(res));
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}