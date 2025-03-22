#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

// Windows:
// 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17
// 	-fsanitize=undefined,address -o A A.cpp'
// Mac: 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17 -o A A.cpp'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N; cin >> N;
    // proof by exhaustion for < 12
    // construction for >= 12 on mod 6 using modular arithmetic
    cout << 2 << "\n"; 
    
    // n = 2,3,4,5,6,7,9,11 not possible
    // settle special base cases <= 12
    if (N == 8) {
        cout << "4 4\n";
    } else if (N == 10) {
        cout << "4 6\n";
    } else {
        ll remainder = N % 6;
        switch(remainder) {
            case 0: case 2: case 4:
            cout << 4 << " " << N - 4 << "\n";
            break;
            case 1:
            cout << 4 << " " << N - 4 << "\n";
            break;
            case 3:
            cout << 6 << " " << N - 6 << "\n";
            break;
            case 5:
            cout << 8 << " " << N - 8 << "\n";
        }
    }
}