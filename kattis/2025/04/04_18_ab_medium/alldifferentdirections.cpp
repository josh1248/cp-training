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

    int n;
    string s;
    while (cin >> n) {
        if (n == 0) return 0;
        getline(cin, s);
        vector<pair<double, double>> coords;
        rep(i, 0, n) {
            getline(cin, s);
            stringstream ss(s);
            vector<string> ins;
            string x;
            while (ss >> x) {
                ins.push_back(x);
            }
            double currx = stold(ins[0]), curry = stold(ins[1]), bearing = stold(ins[3]);
            for (int j = 4; j < sz(ins); j += 2) {
                if (ins[j] == "turn") {
                    bearing = remainder(bearing  + stold(ins[j + 1]), 360.0);
                } else {
                    double dist = stold(ins[j + 1]);
                    currx += dist * cos(bearing * M_PI / 180.0);
                    curry += dist * sin(bearing * M_PI / 180.0);
                }
            }
            coords.push_back({currx, curry});
        }
        double sx = 0, sy = 0;
        for (auto& [a, b]: coords) {
            sx += a, sy += b;
        }
        double avgx = sx / sz(coords), avgy = sy / sz(coords);
        double maxdist = 0;
        for (auto& [a, b]: coords) {
            double dist = (a - avgx) * (a - avgx) + (b - avgy) * (b - avgy);
            maxdist = max(maxdist, dist);
        }
        cout << avgx << " " << avgy << " ";
        cout << pow(maxdist, 0.5) << "\n";
    }
}