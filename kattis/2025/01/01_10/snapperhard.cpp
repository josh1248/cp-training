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
        int n, k;
        cin >> n >> k;
        
        // check that bin representation of k has "...1111111" for the last n bits
        int check = (1 << n) - 1;
        cout << "Case #" << i + 1 << ": ";
        if ((k & check) == check) {
            cout << "ON" << "\n";
        } else {
            cout << "OFF" << "\n";
        }
    }
}