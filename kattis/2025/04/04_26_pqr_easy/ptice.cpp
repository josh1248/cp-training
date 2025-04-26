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

    int n; string s;
    cin >> n >> s;
    string achoice = "ABCABCABCABC",
        bchoice = "BABCBABCBABC",
        gchoice = "CCAABBCCAABB";
    int a = 0, b = 0, g = 0;

    rep(i, 0, sz(s)) {
        if (s[i] == achoice[i % 12]) a++;
        if (s[i] == bchoice[i % 12]) b++;
        if (s[i] == gchoice[i % 12]) g++;
    }
    
    int hi = max({a,b,g});

    cout << hi << "\n";

    if (a == hi) cout << "Adrian\n";
    if (b == hi) cout << "Bruno\n";
    if (g == hi) cout << "Goran\n";
}