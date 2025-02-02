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

    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n, a, b; cin >> n >> a >> b;
        cout << (abs(a - b) % 2 == 0 ? "YES" : "NO") << "\n";
    }
}