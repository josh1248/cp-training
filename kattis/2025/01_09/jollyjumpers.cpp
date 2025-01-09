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

    string s;

    while (getline(cin, s)) {
        stringstream ss(s);
        int n, prev, curr;
        bool flag = true;
        ss >> n;
        vector<bool> b(n, false);

        ss >> prev;
        for (int i = 0; i < n - 1; i++) {
            ss >> curr;
            int v = abs(curr - prev);
            if (v == 0 || v >= n || b[v]) {
                flag = false;
            }

            b[v] = true;
            prev = curr;
        }

        cout << (flag ? "Jolly" : "Not jolly") << "\n";
    }
}