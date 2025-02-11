#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; getline(cin, s);
    string t = "";
    for (char c: s) {
        if (c == ' ') continue;
        t += (char)tolower(c);
    }
    for (int i = 0; i < sz(t) - 1; i++) {
        if (t[i] == t[i + 1]) {
            cout << "Palindrome\n";
            return 0;
        }
    }
    for (int i = 0; i < sz(t) - 2; i++) {
        if (t[i] == t[i + 2]) {
            cout << "Palindrome\n";
            return 0;
        }
    }
    cout << "Anti-palindrome\n";
}