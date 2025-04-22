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

    string s; cin >> s;
    bool choice = false;
    if (s == "Reykjavik") choice = false;
    else if (s == "Kopavogur") choice = false;
    else if (s == "Hafnarfjordur") choice = false;
    else if (s == "Reykjanesbaer") choice = false;
    else if (s == "Akureyri") choice = true;
    else if (s == "Gardabaer") choice = false;
    else if (s == "Mosfellsbaer") choice = false;
    else if (s == "Arborg") choice = false;
    else if (s == "Akranes") choice = false;
    else if (s == "Fjardabyggd") choice = true;
    else if (s == "Mulathing") choice = true;
    else if (s == "Seltjarnarnes") choice = false;

    cout << (choice ? "Akureyri" : "Reykjavik") << "\n";
}