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
ll inf = 10e17;

ll mins_in(string s) {
    return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + (s[4] - '0');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for (int z = 0; z < t; z++) {
        int turnaround; cin >> turnaround;
        int na, nb; cin >> na >> nb;

        vi a_departures, b_departures, a_arrivals, b_arrivals;
        for (int i = 0; i < na; i++) {
            string x, y; cin >> x >> y;
            int leave = mins_in(x), reach = mins_in(y) + turnaround;
            a_departures.push_back(leave);
            b_arrivals.push_back(reach);
        }
        for (int i = 0; i < nb; i++) {
            string x, y; cin >> x >> y;
            int leave = mins_in(x), reach = mins_in(y) + turnaround;
            b_departures.push_back(leave);
            a_arrivals.push_back(reach);
        }
        sort(a_departures.begin(), a_departures.end());
        sort(a_arrivals.begin(), a_arrivals.end());
        sort(b_departures.begin(), b_departures.end());
        sort(b_arrivals.begin(), b_arrivals.end());

        int a_idx = 0, a_res = 0;
        for (int i = 0; i < na; i++) {
            if (a_idx < nb && a_arrivals[a_idx] <= a_departures[i]) {
                a_idx++;
                continue;
            } else {
                a_res++;
            }
        }

        int b_idx = 0, b_res = 0;
        for (int i = 0; i < nb; i++) {
            if (b_idx < na && b_arrivals[b_idx] <= b_departures[i]) {
                b_idx++;
                continue;
            } else {
                b_res++;
            }
        }
        
        cout << "Case #" << z + 1 << ": " << a_res << " " << b_res << "\n";
        
    }
}