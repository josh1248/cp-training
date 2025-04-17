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

    int N; cin >> N;
    vector<bool> b(N);
    rep(i, 0, N) {
        char c; cin >> c;
        b[i] = (c == 'T');
    }

    vector<bool> stack;
    char c;
    while (cin >> c) {
        if (isalpha(c)) {
            stack.push_back(b[c - 'A']);
        } else if (c == '*') {
            bool x = stack.back(); stack.pop_back();
            bool y = stack.back(); stack.pop_back();
            stack.push_back(x && y);
        } else if (c == '+') {
            bool x = stack.back(); stack.pop_back();
            bool y = stack.back(); stack.pop_back();
            stack.push_back(x || y);
        } else {
            bool x = stack.back(); stack.pop_back();
            stack.push_back(!x);
        }
    }
    cout << (stack[0] ? "T" : "F") << "\n";
}