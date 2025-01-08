#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

bool num_count_ok(string& s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= '0' && s[i] <= '9') || (i == s.size() - 1 && s[i] == 'X')) {
            res++;
        }
    }
    return res == 10;
}

bool hyphens_ok(string& s) {
    // no start or end
    if (s[0] == '-' || s[s.size() - 1] == '-') {
        return false;
    }

    // no adjacent
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '-' && s[i - 1] == '-') {
            return false;
        }
    }

    // only 0 to 3
    int c = count_if(s.begin(), s.end(), [](char c){ return c == '-'; });
    if (c > 3) {
        return false;
    }

    // if 3, last one must be before checksum
    if (c == 3 && s[s.size() - 2] != '-') {
        return false;
    }

    return true;
}

vi get_isbn10_digits(string s) {
    s.erase(remove(s.begin(), s.end(), '-'), s.end());
    vi v(10, 0);
    for (int i = 0; i < 9; i++) {
        v[i] = s[i] - '0'; 
    }

    if (s[9] == 'X') {
        v[9] = 10;
    } else {
        v[9] = s[9] - '0';
    }

    return v;
}

bool checksum_ok(vi& v) {
    int res = 0;
    for (int i = 0; i < 10; i++) {
        res += (10 - i) * v[i];
    }
    return res % 11 == 0;
}

int isbn_13_checksum(vi& v) {
    int res = 1 * 9 + 3 * 7 + 1 * 8;
    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            res += 3 * v[i];
        } else {
            res += v[i];
        }
    }

    res = res % 10;
    
    if (res == 0) {
        return 0;
    } else {
        return 10 - res;
    }
}

void solve() {
    string s;
    cin >> s;
    if (!(num_count_ok(s) && hyphens_ok(s))) {
        cout << "invalid\n";
        return;
    }

    vi v = get_isbn10_digits(s);
    if (!checksum_ok(v)) {
        cout << "invalid\n";
        return;
    }

    string res = "978-" + s;
    res[res.size() - 1] = '0' + isbn_13_checksum(v);
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        solve();
    }
}