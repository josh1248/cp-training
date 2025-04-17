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
    vector<string> names(31 * 12);
    vector<int> maxlike(31 * 12, -1);

    int n; scanf("%d\n", &n);
    rep(i, 0, n) {
        char name[100];
        int like, day, month;
        scanf("%s %d %d/%d\n", name, &like, &day, &month);
        int key = day - 1 + 31 * (month - 1);
        if (like > maxlike[key]) {
            maxlike[key] = like;
            names[key] = name;
        }
    }

    vector<string> ans;
    rep(i, 0, 31 * 12) {
        if (maxlike[i] == -1) continue;
        ans.push_back(names[i]);
    }
    sort(all(ans));
    cout << sz(ans) << "\n";
    for (string s: ans) cout << s << "\n";
}