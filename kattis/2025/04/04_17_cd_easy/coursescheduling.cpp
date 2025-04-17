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
    unordered_map<string, unordered_set<string>> choices;
    unordered_map<string, int> selections;
    rep(i, 0, n) {
        string a, b, c; cin >> a >> b >> c;
        string key = a + b;
        if (choices.count(key) == 0) choices[key] = unordered_set<string>();
        if (choices[key].count(c) == 0) {
            choices[key].insert(c);
            if (selections.count(c) == 0) selections[c] = 0;
            selections[c]++;
        }
    }

    vector<string> courses;
    for (auto& [k, v]: selections) {
        courses.push_back(k);
    }
    sort(all(courses));
    for (string s: courses) {
        cout << s << " " << selections[s] << "\n";
    }
}