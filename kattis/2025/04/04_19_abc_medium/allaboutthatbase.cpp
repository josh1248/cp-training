#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

ll val(char c) {
    if (c >= '0' && c <= '9') return (c - '0');
    else if (c >= 'a' && c <= 'z') return 10 + (c - 'a');
    else return 999;
}

ll getnum(string s, int base) {
    ll res = 0;
    for (char c: s) {
        res *= base;
        if (val(c) > base 
            || (val(c) == base && base != 1)
            || (val(c) != 1 && base == 1)) {
            return 0;
        }
        res += val(c);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        string a, op, b, eq, res;
        cin >> a >> op >> b >> eq >> res;
        vi ok;
        rep(i, 1, 37) {
            unsigned long long
                anum = getnum(a, i),
                bnum = getnum(b, i),
                resnum = getnum(res, i);
            
            if (anum == 0 || bnum == 0 || resnum == 0) continue;
            else if (
                (op == "+" && (anum + bnum == resnum)) ||
                (op == "-" && (anum - bnum == resnum)) ||
                (op == "*" && (anum * bnum == resnum)) ||
                (op == "/" && (anum == bnum * resnum))
            ) {
                ok.push_back(i);
            }
        }

        if (sz(ok) == 0) cout << "invalid\n";
        else {
            for (int b: ok) {
                if (b < 10) cout << b;
                else if (b == 36) cout << 0;
                else cout << char(b - 10 + 'a');
            }
            cout << "\n";
        }
    }
}