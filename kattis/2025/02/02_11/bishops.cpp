#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (getline(cin, s)) {
        int t;
        t = stoi(s);
        cout << 2 * t - 2 << "\n";
    }
}