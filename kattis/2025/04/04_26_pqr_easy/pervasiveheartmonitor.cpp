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

    string s;
    cout << setprecision(6) << fixed;
    while (getline(cin, s)) {
        stringstream ss(s);
        string x;
        string name = "";
        double acc = 0;
        int denom = 0;
        while (ss >> x) {
            if (all_of(all(x), [](char c) { return (c >= '0' && c <= '9') || c == '.';})) {
                double f = stold(x);
                acc += f;
                denom++;
            } else {
                if (name != "") name += " ";
                name += x;
            }
        }
        cout << acc / denom << " " << name << "\n";
    }
}