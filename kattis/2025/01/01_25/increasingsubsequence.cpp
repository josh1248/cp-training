#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n; cin >> n;
        if (n == 0) return 0;
        // insert a -1 at the front
        // corr: lis number -> idx mapping
        vi items(1, -1), lis(1, -1), corr(1, -1), parents(n + 1, -1);
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            items.push_back(k);
            ll idx = distance(lis.begin(), lower_bound(all(lis), k));
            if (idx == sz(lis)) {
                lis.push_back(k);
                corr.push_back(i);
                parents[i] = corr[idx - 1];
            } else if (k < lis[idx]) {
                lis[idx] = k;
                corr[idx] = i;
                parents[i] = corr[idx - 1];
            }
        }

        int idx = corr[sz(lis) - 1];
        vi res;
        while (idx >= 0) {
            res.push_back(items[idx+1]);
            idx = parents[idx];
        }
        reverse(all(res));

        cout << sz(res) << " ";
        for (int i: res)
            cout << i << " ";
        cout << "\n";
    }
}