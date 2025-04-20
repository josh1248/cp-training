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

    int n; vi v;
    while (cin >> n) {
        if (n == 0) return 0;
        int totalsum = 0;
        v = vi(n);
        rep(i, 0, n) {
            cin >> v[i];
            totalsum += v[i];
        }

        if (n == 1) cout << totalsum << " " << 0 << "\n";
        else if (n == 2) cout << max(v[0], v[1]) << " " << min(v[0], v[1]) << "\n";
        else {
            // meet in the middle
            int leftsize = n / 2, rightsize = n - n / 2;
            vi left(leftsize), right(rightsize);
            rep(i, 0, leftsize) left[i] = v[i];
            rep(i, 0, rightsize) right[i] = v[leftsize + i];
            vi leftsets(1 << leftsize), rightsets(1 << rightsize);
            rep(mask, 0, (1 << leftsize)) {
                rep(j, 0, leftsize) {
                    if (mask & (1 << j)) leftsets[mask] += left[j];
                }
            }
            rep(mask, 0, (1 << rightsize)) {
                rep(j, 0, rightsize) {
                    if (mask & (1 << j)) rightsets[mask] += right[j];
                }
            }
            sort(all(rightsets));
            int target = (totalsum + 1) / 2;
            int bestdiff = 1e8; int a = -1;
            for (int x: leftsets) {
                int wanted = target - x;
                // cout << "Got: " << x << ", target " << wanted << ", match ";
                auto it = lower_bound(all(rightsets), wanted);
                if (it != rightsets.end()) {
                    int diff = abs(target - *it - x);
                    // cout << *it << " ";
                    if (bestdiff > diff) {
                        bestdiff = diff;
                        a = x + *it;
                    }
                }
                if (it != rightsets.begin()) {
                    int diff = abs(target - *(prev(it)) - x);
                    // cout << *(prev(it)) << " ";
                    if (bestdiff > diff) {
                        bestdiff = diff;
                        a = x + *(prev(it));
                    }
                }
                // cout << "\n";
            }
            cout << max(a, totalsum - a) << " " << min(a, totalsum - a) << "\n";
        }
    }
}