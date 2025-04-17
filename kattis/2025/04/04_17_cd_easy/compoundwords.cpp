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

    vector<string> x; string s;
    while (cin >> s) {
        x.push_back(s);
    }

    unordered_set<string> words;
    rep(i, 0, sz(x)) {
        rep(j, 0, sz(x)) {
            if (i == j) continue;
            string combined = x[i] + x[j];
            if (words.count(combined) == 0) {
                words.insert(combined);
            } 
        }
    }

    vector<string> ans;
    for(auto s: words) {
        ans.push_back(s);
    }
    sort(all(ans));
    for(string s: ans) cout << s << "\n";
}