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

    int start, d1, d2, d3;
    while (cin >> start >> d1 >> d2 >> d3) {
        if (start == 0 && d1 == 0 && d2 == 0 && d3 == 0) {
            return 0;
        }
        
        int turns1;
        if (start >= d1) {
            turns1 = 40 * 2 + start - d1;
        } else {
            turns1 = 40 * 3 + start - d1;
        }

        int turns2;
        if (d1 <= d2) {
            turns2 = 40 + d2 - d1; 
        } else {
            turns2 = 40 * 2 + d2 - d1;
        }

        int turns3;
        if (d2 >= d3) {
            turns3 = d2 - d3;
        } else {
            turns3 = 40 + d2 - d3;
        }
        cout << 9 * (turns1 + turns2 + turns3) << "\n"; 
    }
}