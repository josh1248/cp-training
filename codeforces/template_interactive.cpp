#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).begin()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int lo = 1, high = 1000000;
    while (lo < high) {
        int mid = (lo + high + 1) / 2;
        cout << mid << "\n" << flush;
        string s; cin >> s;
        if (s == ">=") {
            lo = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << "! " << lo << "\n";
}