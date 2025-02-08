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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    int hold;
    vi v;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (i == k) {
            hold = x;
        } else {
            v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    v.insert(v.begin(), hold);

    int running_time = 0, solves = 0, penalty = 0;
    for (int i = 0; i < v.size(); i++) {
        if (running_time + v[i] <= 300) {
            solves++;
            penalty += running_time + v[i];
            running_time += v[i];
        } else {
            break;
        }
    }
    cout << solves << " " << penalty << "\n";
}