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

    int n; cin >> n;
    string s; cin >> s;
    vector<char> stack;
    for (char c: s) {
        if (c == '(' || c == '[' || c == '{') stack.push_back(c);
        else if (sz(stack) == 0) {
            cout << "Invalid\n";
            return 0;
        } else if (c == ']' && stack.back() == '[') stack.pop_back();
        else if (c == ')' && stack.back() == '(') stack.pop_back();
        else if (c == '}' && stack.back() == '{') stack.pop_back();
        else {
            cout << "Invalid\n";
            return 0;
        }
    }
    cout << (sz(stack) == 0 ? "Valid" : "Invalid") << "\n";
}