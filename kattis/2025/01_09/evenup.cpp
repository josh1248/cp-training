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
    vi v;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        v.push_back(k);
        while (v.size() >= 2 && (v[v.size() - 1] + v[v.size() - 2]) % 2 == 0) {
            v.erase(v.end() - 1);
            v.erase(v.end() - 1);
        }
    }
    cout << v.size() << "\n";
}