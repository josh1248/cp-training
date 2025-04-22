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

    string s; cin >> s;
    stringstream ss(s);
    string x;
    ll acc = 0;
    while (getline(ss, x, ';')) {
        if (x.find('-') == string::npos) {
            acc++;
        } else {
            ll lo = stoi(x.substr(0, x.find('-'))),
                high = stoi(x.substr(x.find('-') + 1));
            acc += high - lo + 1;
        }
    }
    cout << acc << "\n";
}