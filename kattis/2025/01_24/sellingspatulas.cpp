#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).begin()


signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    int x;
    while (true) {
        cin >> x;
        if (x == 0) {
            return 0;
        }
        // dp[i]: max profit assuming open at datatimes[i]
        vector<ll> dp(x);
        vi close(x);
        vector<ll> datatimes(x), dataprofits(x);
        ll currTime; double tmp;
        for (int i = 0; i < x; i++) {
            scanf("%lld %lf\n", &currTime, &tmp);
            datatimes[i] = currTime;
            dataprofits[i] = ll(round(tmp * 100));
        }

        dp[x - 1] = dataprofits[x - 1] - 8ll;
        close[x - 1] = datatimes[x - 1];
        for (int i = x - 2; i >= 0; i--) {
            // open for that minute only
            ll open1 = dataprofits[i] - 8ll;
            // compare to usage of best profit of subsequent times
            ll open2 = dataprofits[i] + dp[i + 1] - 8ll * (datatimes[i + 1] - datatimes[i]);
            if (open1 >= open2) {
                dp[i] = open1;
                close[i] = datatimes[i];
            } else {
                dp[i] = open2;
                close[i] = close[i + 1];
            }
        }

        ll maxgain = 0, l = 0, r = 1e9;
        for (int i = 0; i < x; i++) {
            if (dp[i] > maxgain) {
                maxgain = dp[i];
                l = datatimes[i];
                r = close[i];
            } else if (dp[i] == maxgain && (((r - l) > (close[i] - datatimes[i])))) {
                l = datatimes[i];
                r = close[i];
            }
        }

        if (maxgain == 0) {
            cout << "no profit\n";
        } else {
            printf("%lld.%02lld %lld %lld\n", maxgain / 100, maxgain % 100, l, r);
        }
    } 
}