#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

void solve() {
    // in "functional"
    function<int(int)> fibs = [&](int i) {
        if (i == 0) return 0;
        if (i == 1) return 1;
        return fibs(i - 1) + fibs(i - 2); // ignore the time complexity
    };

    cout << fibs(8) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   
    solve();
}