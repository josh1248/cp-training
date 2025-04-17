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
    string s; getline(cin, s); getline(cin, s);
    vector<char> brackets;
    rep(i, 0, sz(s)) {
        if (s[i] == '(') {
            brackets.push_back(s[i]);
        } else if (s[i] == '{') {
            brackets.push_back(s[i]);
        } else if (s[i] == '[') {
            brackets.push_back(s[i]);
        } else if (s[i] == ')') {
            if (sz(brackets) == 0 || brackets[sz(brackets) - 1] != '(') {
                cout << s[i] << " " << i << "\n";
                return 0;
            }
            brackets.pop_back();
        } else if (s[i] == ']') {
            if (sz(brackets) == 0 || brackets[sz(brackets) - 1] != '[') {
                cout << s[i] << " " << i << "\n";
                return 0;
            }
            brackets.pop_back();
        } else if (s[i] == '}') {
            if (sz(brackets) == 0 || brackets[sz(brackets) - 1] != '{') {
                cout << s[i] << " " << i << "\n";
                return 0;
            }
            brackets.pop_back();
        }
    }
    cout << "ok so far\n";
}