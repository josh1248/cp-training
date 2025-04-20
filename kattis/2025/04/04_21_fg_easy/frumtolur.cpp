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

    int hit = 1, curr = 3;
    cout << 2 << "\n";
    while (hit < 100) {
        bool isprime = true;
        rep(j, 2, round(pow(curr, 0.5) + 1)) {
            if (curr % j == 0) isprime = false;
        }
        if (isprime) {
            cout << curr << "\n";
            hit++;
        }
        curr++;
    }
}