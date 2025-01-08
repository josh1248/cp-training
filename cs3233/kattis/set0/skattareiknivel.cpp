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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // avoid floating point shenanigans by multiplying % by 10000
    string t1, t2;
    cin >> t1 >> t2;

    ll l = (t1[0] - '0') * 100 + (t1[2] - '0') * 10 + (t1[3] - '0') * 1;
    ll s = (t2[0] - '0') * 100 + (t2[2] - '0') * 10 + (t2[3] - '0') * 1;
    ll b1_tax = 3145;
    ll b2_tax = 3795;
    ll b3_tax = 4625;
    ll exemption = 59665;

    ll res = 0;
    ll accrued_exemption = 0;

    for (int i = 0; i < 12; i++) {
        accrued_exemption += exemption;
        ll base;
        cin >> base;

        ll pen1 = ((base * l) / 10000);
        ll pen2 = ((base * s) / 10000);
        base -= pen1;
        base -= pen2;
        
        ll left = base;
        ll bracket1 = min(left, 409986LL);
        left -= bracket1;
        ll bracket2 = min(left, 1151012LL - 409986LL);
        left -= bracket2;
        ll bracket3 = left;
        ll total_tax = (bracket1 * b1_tax + bracket2 * b2_tax + bracket3 * b3_tax) / 10000;
       
        ll tmp = accrued_exemption;
        accrued_exemption = max(0LL, accrued_exemption - total_tax);
        total_tax = max(0LL, total_tax - tmp);

        res += base - total_tax;
    }
    cout << res << "\n";
}