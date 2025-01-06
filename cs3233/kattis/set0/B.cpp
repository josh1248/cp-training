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
typedef pair<int, int> pi;
typedef long long ll;

// binary addition
// b == 1, a == 0, leftmost rune is ones digit
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d; string s;
    cin >> s >> d;

    // rune to int
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') {
            res += 1 << i;
        }
    }

    res += d;
    
    // int to rune
    for (int i = 0; i < s.size(); i++) {
        // i-th bit
        int r = (res & (1 << i)) >> i;
        cout << (r == 0 ? 'A' : 'B'); 
    }
    cout << "\n";
}