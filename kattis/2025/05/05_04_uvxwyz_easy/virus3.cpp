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

    string a, b; cin >> a >> b;
    int curr = 0;
    int i = 0;
    while (curr < sz(a) && i < sz(b)) {
        if (a[curr] == b[i]) curr++;
        i++;
    }
    cout << (curr == sz(a) ? "Ja" : "Nej") << "\n";
}