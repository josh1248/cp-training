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

    string s, e; cin >> s >> e;
    int time1 = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    int time2 = stoi(e.substr(0, 2)) * 60 + stoi(e.substr(3));
    if (time1 > time2) time2 += 24 * 60;
    cout << time2 - time1 << "\n";
}