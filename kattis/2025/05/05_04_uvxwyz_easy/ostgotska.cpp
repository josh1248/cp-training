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
    int hits = 0;
    int words = 0;
    while (cin >> s) {
        words++;
        if (s.find("ae") != string::npos) hits++;
    }
    if (hits * 10 >= words * 4) {
        cout << "dae ae ju traeligt va\n";
    } else {
        cout << "haer talar vi rikssvenska\n";
    }
}