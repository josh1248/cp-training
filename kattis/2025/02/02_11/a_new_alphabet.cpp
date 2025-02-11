#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

const string maps[26] = {
    "@",
    "8",
    "(",
    "|)",
    "3",
    "#",
    "6",
    "[-]",
    "|",
    "_|",
    "|<",
    "1",
    "[]\\/[]",
    "[]\\[]",
    "0",
    "|D",
    "(,)",
    "|Z",
    "$",
    "']['",
    "|_|",
    "\\/",
    "\\/\\/",
    "}{",
    "`/",
    "2"
};

void convert(char c) {
    char t = (char)tolower(c);
    if (t >= 'a' && t <= 'z') {
        cout << maps[t-'a'];
    } else {
        cout << t;
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    string s;
    getline(cin, s);
    for (char c: s) {
        convert(c);
    }
    cout << "\n";
}