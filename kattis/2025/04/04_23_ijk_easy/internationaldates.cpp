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
    bool us = true, eu = true;
    int front = stoi(s.substr(0, 2)), mid = stoi(s.substr(3, 2));
    if (front > 12) us = false;
    if (mid > 12) eu = false;
    if (eu && us) cout << "either\n";
    else if (eu) cout << "EU\n";
    else cout << "US\n";
}