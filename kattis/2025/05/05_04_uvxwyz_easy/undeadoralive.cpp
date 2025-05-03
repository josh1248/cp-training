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

    string s; getline(cin, s);
    bool smile = s.find(":)") != string::npos;
    bool sad = s.find(":(") != string::npos;
    if (smile && sad) cout << "double agent\n";
    else if (smile) cout << "alive\n";
    else if (sad) cout << "undead\n";
    else cout << "machine\n";
}