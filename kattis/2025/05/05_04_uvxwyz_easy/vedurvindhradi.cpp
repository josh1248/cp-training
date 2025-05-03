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

    string x; cin >> x;
    int d = 10 * stoi(x.substr(0, 3)) + stoi(x.substr(sz(x) - 1, 1));
    if (d <= 2) cout << "Logn\n";
    else if (d <= 15) cout << "Andvari\n";
    else if (d <= 33) cout << "Kul\n";
    else if (d <= 54) cout << "Gola\n";
    else if (d <= 79) cout << "Stinningsgola\n";
    else if (d <= 107) cout << "Kaldi\n";
    else if (d <= 138) cout << "Stinningskaldi\n";
    else if (d <= 171) cout << "Allhvass vindur\n";
    else if (d <= 207) cout << "Hvassvidri\n";
    else if (d <= 244) cout << "Stormur\n";
    else if (d <= 284) cout << "Rok\n";
    else if (d <= 326) cout << "Ofsavedur\n";
    else cout << "Farvidri\n";
}