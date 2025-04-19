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

    int n, m; cin >> n >> m;
    string flush; getline(cin, flush);
    vector<string> drinks(n);
    rep(i, 0, n) getline(cin, drinks[i]); 
    unordered_map<string, int> mapping;
    rep(i, 0, m) {
        string s; cin >> s;
        if (mapping.count(s) == 0) {
            mapping[s] = 0;
        }
        cout << drinks[mapping[s]++] << "\n";
    }
}