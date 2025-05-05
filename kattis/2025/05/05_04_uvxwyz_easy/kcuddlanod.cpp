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
    for (char& c: a) {
        if (c == '2') c = '5';
        else if (c == '5') c = '2';
    }
    for (char& c: b) {
        if (c == '2') c = '5';
        else if (c == '5') c = '2';
    }
    reverse(all(a)), reverse(all(b));
    cout << (stoi(a) > stoi(b) ? 1 : 2) << "\n";
}