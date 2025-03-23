#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    stringstream ss(s);
    string read;
    while (getline(ss, read, '-')) {
        cout << read[0];
    }
    cout << "\n";
    return 0;
}