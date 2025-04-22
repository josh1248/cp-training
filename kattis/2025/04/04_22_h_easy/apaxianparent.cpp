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

    string Y, P; cin >> Y >> P;
    string vowels = "aeiou";
    bool removed = false;
    for (char c: vowels) {
        if (Y[sz(Y) - 1] == c) {
            Y.pop_back();
            removed = true;
            break;
        }
    }
    if (!removed && sz(Y) >= 2 && Y[sz(Y) - 1] == 'x' && Y[sz(Y) - 2] == 'e') {
        Y.pop_back();
        Y.pop_back();
    }
    cout << Y + "ex" + P << "\n";
}