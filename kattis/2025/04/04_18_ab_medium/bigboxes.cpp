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

    int n, k; cin >> n >> k;
    vi boxes(n);
    int heaviest = -1;
    rep(i, 0, n) {
        cin >> boxes[i];
        heaviest = max(heaviest, boxes[i]);
    }

    int low = heaviest, high = 1e9;
    while (low < high) {
        int mid = (low + high) / 2;
        int boxes_left = k;
        int curr_cap = mid;
        bool possible = true;
        rep(i, 0, n) {
            if (curr_cap < boxes[i]) {
                if (boxes_left <= 1) {
                    possible = false;
                    break;
                }
                boxes_left--;
                curr_cap = mid;
            }
            curr_cap -= boxes[i];
        }
        if (possible) high = mid;
        else low = mid + 1;
    }
    cout << low << "\n";
}